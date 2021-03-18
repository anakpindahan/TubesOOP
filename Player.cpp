#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){
	coordinate = Cell(0, 0, "Grass");
}

Player::Player(const Player& p){
	this->coordinate = p.coordinate;
}

Player& Player::operator=(const Player& p){
	this->coordinate = p.coordinate;
	return *this;
}

Player::~Player(){

}

Cell Player::getCoordinate(){
	return coordinate;
}

void Player::setCoordinate(Cell c){
	coordinate = c;
}
