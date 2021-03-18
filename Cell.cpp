#include "Cell.hpp"
#include <iostream>
using namespace std;

Cell::Cell(){
	X = 0;
	Y = 0;
	type = "Grass";
}

Cell::Cell(int _X, int _Y, string _type){
	X = _X;
	Y = _Y;
	type = _type;
}

Cell::Cell(const Cell& c){
	X = c.X;
	Y = c.Y;
	type = c.type;
}

Cell& Cell::operator=(const Cell& c){
	Cell c1(c.X, c.Y, c.type);
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

void Cell::setX(int _X){
	X = _X;
}

void Cell::setY(int _Y){
	Y = _Y;
}

void Cell::setType(string _type){
	type = _type;
}
