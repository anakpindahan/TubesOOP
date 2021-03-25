#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){
	coordinate = Cell(0, 0, "Grass", "Player", 'P');
	currSymbol = '-';
}

Player& Player::operator=(const Player& p){
	this->coordinate = p.coordinate;
	this->currSymbol = p.currSymbol;
	return *this;
}

Player::~Player(){

}

Cell Player::getCoordinate(){
	return coordinate;
}

char Player::getCurrCymbol(){
	return currSymbol;
}

void Player::setCoordinate(Cell c){
	coordinate = c;
}

void Player::setCoordinate(int _X, int _Y){
	coordinate.setX(_X);
	coordinate.setY(_Y);
}

void Player::setCurrSymbol(char _currSymbol){
	currSymbol = _currSymbol;
}

void Player::setEngimon(Engimon engimon){
	this->engimon = engimon;
}
