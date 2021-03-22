#include "Cell.hpp"
#include <iostream>
using namespace std;

Cell::Cell(){
	X = 0;
	Y = 0;
	type = "NoType";
	entity = "Air";
	symbol = 'X';
}

Cell::Cell(int _X, int _Y, string _type, string _entity, char _symbol){
	X = _X;
	Y = _Y;
	type = _type;
	entity = _entity;
	symbol = _symbol;
}

Cell::Cell(const Cell& c){
	X = c.X;
	Y = c.Y;
	type = c.type;
	entity = c.entity;
	symbol = c.symbol;
}

Cell& Cell::operator=(const Cell& c){
	Cell c1(c.X, c.Y, c.type, c.entity, c.symbol);
}

Cell::~Cell(){
	
}

int Cell::getX(){
	return X;
}

int Cell::getY(){
	return Y;
}

string Cell::getType(){
	return type;
}

string Cell::getEntity(){
	return entity;
}

char Cell::getSymbol(){
	return symbol;
}

void Cell::setX(int _X){
	X = _X;
}

void Cell::setY(int _Y){
	Y = _Y;
}

void Cell::setType(string _type){
	type = _type;
}

void Cell::setEntity(string _entity){
	entity = _entity;
}

void Cell::setSymbol(char _symbol){
	symbol = _symbol;
}

ostream& operator<<(ostream &out, const Cell& c){
	return out << c.symbol;
}

void Cell::setNaturalSymbol(){
	if(type == "Grass"){
		symbol = '-';
	} else if(type == "Sea") {
		symbol = 'o';
	}
}
