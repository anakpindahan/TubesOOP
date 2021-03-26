#include <cctype>
#include "RealEngimon.h"

using namespace std;

RealEngimon::RealEngimon() :
		Engimon::Engimon() {
	coordinate = Cell(5, 6, "Grass", "WEng", 'W');
	level = 2;
	xp = 5;
	cumulXp = 205;
	name = "No Name";
	parentName1 = "Fulan";
	parentName2 = "Fulanah";
	speciesParent1 = "-";
	speciesParent2 = "-";
	status = WILD_ENGIMON;
}

RealEngimon::RealEngimon(int _id, int _status, string _species, string _slogan, int _maxExp,
		Cell _coordinate, int _level, int _xp, string _name) :
		Engimon::Engimon(_id, _species, _slogan, _maxExp) {
	coordinate = _coordinate;
	level = _level;
	xp = _xp;
	cumulXp = (level - 1) * 100 + xp;
	name = _name;
	parentName1 = "Fulan";
	parentName2 = "Fulanah";
	speciesParent1 = "-";
	speciesParent2 = "-";
	status = _status;
}

RealEngimon::RealEngimon(const RealEngimon& we) : Engimon::Engimon(we) {
	coordinate = we.coordinate;
	level = we.level;
	xp = we.xp;
	cumulXp = we.cumulXp;
	name = we.name;
	parentName1 = we.parentName1;
	parentName2 = we.parentName2;
	speciesParent1 = we.speciesParent1;
	speciesParent2 = we.speciesParent2;
	status = we.status;
}

RealEngimon& RealEngimon::operator=(const RealEngimon& we){
	this->id = we.id;
	this->species = we.species;
	this->slogan = we.slogan;
	this->maxExp = we.maxExp;
	this->coordinate = we.coordinate;
	this->level = we.level;
	this->xp = we.xp;
	this->cumulXp = we.xp;
	this->name = we.name;
	this->parentName1 = we.parentName1;
	this->parentName2 = we.parentName2;
	this->speciesParent1 = we.speciesParent1;
	this->speciesParent2 = we.speciesParent2;
	this->status = we.status;
	this->setSymbol();
	this->Engimon::operator=(we);
	return *this;
}

RealEngimon::~RealEngimon() {

}

Cell RealEngimon::getCoordinate() {
	return coordinate;
}

int RealEngimon::getLevel() {
	return level;
}

int RealEngimon::getXp() {
	return xp;
}

int RealEngimon::getCumulXp() {
	return level * 100 + xp;
}

string RealEngimon::getName() {
	return name;
}

string RealEngimon::getParentName1() {
	return parentName1;
}

string RealEngimon::getParentName2() {
	return parentName2;
}

string RealEngimon::getSpeciesParent1() {
	return speciesParent1;
}

string RealEngimon::getSpeciesParent2() {
	return speciesParent2;
}

void RealEngimon::setCoordinate(Cell _coordinate) {
	coordinate = _coordinate;
}

void RealEngimon::setCoordinate(int _X, int _Y) {
	coordinate.setX(_X);
	coordinate.setY(_Y);
}

void RealEngimon::setLevel(int _level) {
	level = _level;
}

void RealEngimon::setXp(int _xp) {
	xp = _xp;
}

void RealEngimon::setName(string _name) {
	name = _name;
}

void RealEngimon::setParentName1(string _parentName1) {
	parentName1 = _parentName1;
}

void RealEngimon::setParentName2(string _parentName2) {
	parentName2 = _parentName2;
}

void RealEngimon::setSpeciesParent1(string _speciesParent1) {
	speciesParent1 = _speciesParent1;
}

void RealEngimon::setSpeciesParent2(string _speciesParent2) {
	speciesParent2 = _speciesParent2;
}

void RealEngimon::setCumulXp(int _cumulXp) {
	cumulXp = _cumulXp;
	level = 1 + (cumulXp / 100);
	xp = cumulXp % 100;
}

void RealEngimon::xpUp(int dXp) {
	cumulXp += dXp;
	if (cumulXp >= maxExp) {
		delete this;
	} else {
		if (xp + dXp >= 100) {
			levelUp((xp + dXp / 100));
		}
		xp = (xp + dXp) % 100;
	}

}

void RealEngimon::levelUp(int dLevel) {
	level += dLevel;
}

bool RealEngimon::isSuitable(Cell c) {
	if (symbol == 'F' || symbol == 'G' || symbol == 'E' || symbol == 'L') {
		return (c.getType() == "Grass");
	} else if (symbol == 'W' || symbol == 'I' || symbol == 'S') {
		return (c.getType() == "Sea");
	} else if (symbol == 'N') {
		return true;
	} else {
		return false;
	}
}

void RealEngimon::setSymbolLevel() {
	if (level >= CAPITAL_LEVEL) {
		symbol = toupper(symbol);
	} else {
		symbol = tolower(symbol);
	}
}

RealEngimon RealEngimon::breed(RealEngimon w) {
	RealEngimon child;
	if (legalToBreed(*this, w)) {
		level -= 30;
		w.level -= 30;
		child.setCumulXp(0);
		child.setParentName1(name);
		child.setParentName2(w.name);
		child.setSpeciesParent1(species);
		child.setSpeciesParent2(w.species);
		if(species == w.species){
			child.id = id;
			child.species = species;
			child.slogan = slogan;
			child.symbol = symbol;
		}
		child.inheritElement(*this, w);
		child.inheritSkill(*this, w);
		return child;
	} else {
		throw(Exception(UNSUITABLE_BREED));
	}
}

bool RealEngimon::legalToBreed(RealEngimon w1, RealEngimon w2) {
	if (w1.level > 30 && w2.level > 30) {
		if (w1.numElements == 1 && w2.numElements == 1) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

int RealEngimon::getStatus() {
	return status;
}

void RealEngimon::setStatus(int _status) {
	this->status = _status;
}

void RealEngimon::showStat() {
//	cout << "Nomor Urut" <<
	cout << "Id: " << id << endl;
	cout << "Nama: " << name << endl;
	cout << "Spesies: " << species << endl;
	cout << "Banyak elemen: " << numElements << endl;
	cout << "Elemen: ";
	for(int i = 0; i < numElements; i++){
		cout << elements[i] << " ";
	}
	cout << endl;
	cout << "Skill: " << endl;
	priority_queue<Skill> pq = skill;
	while(!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}
	cout << "Slogan: " << slogan << endl;
	cout << "Simbol di peta: " << symbol << endl;
	cout << "Level: " << level << endl;
	cout << "XP:" << xp << endl;
	cout << "Total XP:" << cumulXp << endl;
	cout << "Ayah: " << endl;
	cout << "       Nama: " << parentName1 << endl;
	cout << "       Spesies: " << speciesParent1 << endl;
	cout << "Ibu:" << endl;
	cout << "       Nama: " << parentName2 << endl;
	cout << "       Spesies: " << speciesParent2 << endl;
	cout << "Xp maksimal: " << maxExp << endl;
}
