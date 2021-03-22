#include "WildEngimon.h"
#include <iostream>
using namespace std;

WildEngimon::WildEngimon() : Engimon::Engimon(){
	coordinate = Cell(5, 6, "Grass", "WEng", 'W');
	level = 2;
	xp = 5;
	cumulXp = 205;
}

WildEngimon::WildEngimon(int _id, string _species, string _slogan, int _maxExp, Cell _coordinate, int _level, int _xp) : Engimon::Engimon(_id, _species, _slogan, _maxExp){
	coordinate = _coordinate;
	level = _level;
	xp = _xp;
	cumulXp = level * 100 + xp;
}

WildEngimon::WildEngimon(const WildEngimon& we){
	id = we.id;
	coordinate = we.coordinate;
	level = we.level;
	xp = we.xp;
	cumulXp = we.cumulXp;
}

WildEngimon& WildEngimon::operator=(const WildEngimon& we){
	this->coordinate = we.coordinate;
	this->level = we.level;
	this->xp = we.xp;
	this->cumulXp = we.xp;
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
