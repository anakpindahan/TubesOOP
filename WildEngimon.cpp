#include "WildEngimon.h"
#include <iostream>
using namespace std;

WildEngimon::WildEngimon(){
	id = 0;
	coordinate = Cell(5, 6, "Grass", "WEng");
	level = 2;
	xp = 205;
}

WildEngimon::WildEngimon(int _id, Cell _coordinate, int _level, int _xp){
	id = _id;
	coordinate = _coordinate;
	level = _level;
	xp = _xp;
}

WildEngimon::WildEngimon(const WildEngimon& we){
	id = we.id;
	coordinate = we.coordinate;
	level = we.level;
	xp = we.xp;
}

WildEngimon& WildEngimon::operator=(const WildEngimon& we){
	this->coordinate = we.coordinate;
	this->id = we.id;
	this->level = we.level;
	this->xp = we.xp;
	return *this;
}

WildEngimon::~WildEngimon(){
	
}

int WildEngimon::getId(){
	return id;
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

void WildEngimon::setId(int _id){
	id = _id;
}

void WildEngimon::setCoordinate(Cell _coordinate){
	coordinate = _coordinate;
}

void WildEngimon::setLevel(int _level){
	level = _level;
}

void WildEngimon::setXp(int _xp){
	xp = _xp;
}
