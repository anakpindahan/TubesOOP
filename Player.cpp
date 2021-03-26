#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(){
	coordinate = Cell(0, 0, "Grass", "Player", 'P');
	currSymbol = '-';
	// InventoryEngimon<RealEngimon> *x = new InventoryEngimon<RealEngimon>();
	activeEngimonId = -1;
	prevCoordinate = Cell(0, 0, "Grass", "AEng", 'A');
 }

Player& Player::operator=(const Player& p){
	this->coordinate = p.coordinate;
	this->prevCoordinate = p.prevCoordinate;
	this->currSymbol = p.currSymbol;
	inventoryEngimon = p.inventoryEngimon;
	activeEngimonId = p.activeEngimonId;
	return *this;
}

Player::~Player(){

}

Cell Player::getCoordinate(){
	return coordinate;
}

Cell Player::getPrevCoordinate(){
	return prevCoordinate;
}

Cell Player::getEngimonCoordinate(){
	return engimon.getCoordinate();
}

char Player::getCurrCymbol(){
	return currSymbol;
}

int Player::getActiveEngimon(){
	return activeEngimonId;
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

void Player::setEngimon(RealEngimon engimon){
	this->engimon = engimon;
}

void Player::setEngimonCoordinate(int _X, int _Y){
	engimon.setCoordinate(_X, _Y);
}

void Player::setActiveEngimon(int _activeEngimonId){
	engimon = inventoryEngimon.getEngimon(_activeEngimonId);
	activeEngimonId = _activeEngimonId;
}

InventoryEngimon<RealEngimon>& Player::getInventoryEngimon(){
	return inventoryEngimon;
}

InventorySkill& Player::getInventorySkill(){
	return inventorySkill;
}

void Player::addEngimon(RealEngimon e){
	inventoryEngimon.putIn(e);
}

void Player::addSkill(string skill){
	this->inventorySkill.addItem(skill);
}
void Player::useSkill(string skillname){
	this->inventorySkill.useItem(skillname);
}

void Player::setPrevCoordinate(Cell cell) {
	prevCoordinate = cell;
}

void Player::setPrevCoordinate(int _X, int _Y) {
	prevCoordinate.setX(_X);
	prevCoordinate.setY(_Y);
}

void Player::interact(){
	cout << engimon.getName() << "(" << engimon.getSpecies() << ")" << ": " << engimon.getSlogan() << endl;
}
