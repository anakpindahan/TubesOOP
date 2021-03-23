#include "WildEngimon.h"
#include <iostream>
using namespace std;

WildEngimon::WildEngimon() : Engimon::Engimon(){
	coordinate = Cell(5, 6, "Grass", "WEng", 'W');
	level = 2;
	xp = 5;
	cumulXp = 205;
	name = "No Name";
	parentName1 = "Fulan";
	parentName2 = "Fulanah";
	speciesParent1 = "-";
	speciesParent2 = "-";
}

WildEngimon::WildEngimon(int _id, string _species, string _slogan, int _maxExp, Cell _coordinate, int _level, int _xp, string _name) : Engimon::Engimon(_id, _species, _slogan, _maxExp){
	coordinate = _coordinate;
	level = _level;
	xp = _xp;
	cumulXp = level * 100 + xp;
	name = _name;
	parentName1 = "Fulan";
	parentName2 = "Fulanah";
	speciesParent1 = "-";
	speciesParent2 = "-";
}

WildEngimon::WildEngimon(const WildEngimon& we){
	id = we.id;
	coordinate = we.coordinate;
	level = we.level;
	xp = we.xp;
	cumulXp = we.cumulXp;
	name = we.name;
	parentName1 = we.parentName1;
	parentName2 = we.parentName2;
	speciesParent1 = we.speciesParent1;
	speciesParent2 = we.speciesParent2;
}

WildEngimon& WildEngimon::operator=(const WildEngimon& we){
	this->coordinate = we.coordinate;
	this->level = we.level;
	this->xp = we.xp;
	this->cumulXp = we.xp;
	this->name = we.name;
	this->parentName1 = we.parentName1;
	this->parentName2 = we.parentName2;
	this->speciesParent1 = we.speciesParent1;
	this->speciesParent2 = we.speciesParent2;
	return *this;
}


WildEngimon::~WildEngimon(){
	
}

Cell WildEngimon::getCoordinate(){
	return coordinate;
}

int WildEngimon::getLevel(){
	return level;
}

int WildEngimon::getXp(){
	return xp;
}

int WildEngimon::getCumulXp(){
	return level * 100 + xp;
}

string WildEngimon::getName(){
	return name;
}

string WildEngimon::getParentName1(){
	return parentName1;
}

string WildEngimon::getParentName2(){
	return parentName2;
}

string WildEngimon::getSpeciesParent1(){
	return speciesParent1;
}

string WildEngimon::getSpeciesParent2(){
	return speciesParent2;
}

void WildEngimon::setCoordinate(Cell _coordinate){
	coordinate = _coordinate;
}

void WildEngimon::setCoordinate(int _X, int _Y){
	coordinate.setX(_X);
	coordinate.setY(_Y);
}

void WildEngimon::setLevel(int _level){
	level = _level;
}

void WildEngimon::setName(string _name){
	name = _name;
}

void WildEngimon::setParentName1(string _parentName1){
	parentName1 = _parentName1;
}

void WildEngimon::setParentName2(string _parentName2){
	parentName2 = _parentName2;
}

void WildEngimon::setSpeciesParent1(string _speciesParent1){
	speciesParent1 = _speciesParent1;
}

void WildEngimon::setSpeciesParent2(string _speciesParent2){
	speciesParent2 = _speciesParent2;
}

void WildEngimon::setXp(int _xp){
	xp = _xp;
}

void WildEngimon::xpUp(int dXp){
	if(cumulXp >= maxExp){
		delete this;
	} else {
		if(xp + dXp >= 100){
			levelUp((xp + dXp / 100));
		}
		xp = (xp + dXp) % 100;		
	}

}

void WildEngimon::levelUp(int dLevel){
	level += dLevel;
}

bool WildEngimon::isSuitable(Cell c){
	if(symbol == 'F' || symbol == 'G' || symbol == 'E' || symbol == 'L'){
		return(c.getType() == "Grass");
	} else if(symbol == 'W' || symbol == 'I' || symbol == 'S'){
		return(c.getType() == "Sea");
	} else if(symbol == 'N'){
		return true;
	} else {
		return false;
	}
}

void WildEngimon::setSymbolLevel(){
	if(level >= CAPITAL_LEVEL){
		symbol = toupper(symbol);
	} else {
		symbol = tolower(symbol);
	}
}

WildEngimon WildEngimon::breed(WildEngimon w){
	WildEngimon child;
	if(legalToBreed(*this, w)){
		cumulXp -= 300;
		w.cumulXp -= 300;
		level -= 30;
		w.level -= 30;
		if(elements[0] == w.elements[0]){
			child.addElements(elements[0]);
		} else {
			child.addElements(elements[0]);
			child.addElements(w.elements[0]);
		}
		child.setLevel(0);
		child.setParentName1(name);
		child.setParentName2(w.name);
		child.setSpeciesParent1(species);
		child.setSpeciesParent2(w.species);
		return child;
	}
}

bool WildEngimon::legalToBreed(WildEngimon w1, WildEngimon w2){
	if(w1.level >= 30 && w2.level >= 30){
		if(w1.elements[0] == w2.elements[0]){
			return(w1.numElements == 1 && w2.numElements == 1);
		} else if((w1.elements[0] == "Fire" && w2.elements[0] == "Electric") || (w2.elements[0] == "Fire" && w1.elements[0] == "Electric")){
			return true;
		} else if((w1.elements[0] == "Water" && w2.elements[0] == "Ice") || (w2.elements[0] == "Water" && w1.elements[0] == "Ice")){
			return true;
		} else if((w1.elements[0] == "Water" && w2.elements[0] == "Ground") || (w2.elements[0] == "Water" && w1.elements[0] == "Ground")){
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}
