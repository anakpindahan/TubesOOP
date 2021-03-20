#include "Cell.hpp"
#include <iostream>
using namespace std;

Cell::Cell(){
	X = 0;
	Y = 0;
	type = "NoType";
	entity = "Air";
}

Cell::Cell(int _X, int _Y, string _type, string _entity){
	X = _X;
	Y = _Y;
	type = _type;
	entity = entity;
}

Cell::Cell(const Cell& c){
	X = c.X;
	Y = c.Y;
	type = c.type;
	entity = c.entity;
}

Cell& Cell::operator=(const Cell& c){
	Cell c1(c.X, c.Y, c.type, c.entity);
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

ostream& operator<<(ostream &out, const Cell& c){
	if(c.entity == "Air"){
		if(c.type == "Grass"){
			return out << '-';
		} else if(c.type == "Sea"){
			return out << 'o';
		}		
	} else if(c.entity == "Player"){
		return out << 'P';
	} else if(c.entity == "WEng"){
		return out << 'W';
	}

}
