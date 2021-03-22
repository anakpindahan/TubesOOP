#include "Engimon.hpp"
#include <iostream>
using namespace std;

Engimon::Engimon(){
	id = -1;
	species = "-";
	slogan = "-";
	//skill = new Skill[MAX_SKILL];
	elements = new string[MAX_ELEMENTS];
	elements[0] = "Fire";
	maxExp = 0;
	symbol = '/';
	setSymbol();
}

Engimon::Engimon(int _id, string _species, string _slogan, int _maxExp){
	id = _id;
	species = _species;
	/*for(int i = 0; i < MAX_SKILL; i++){
		skill[i] = _skill;
	}*/
	slogan = _slogan;
	elements = new string [MAX_ELEMENTS];
	maxExp = _maxExp;
	setSymbol();
	numElements = 0;
}

Engimon& Engimon::operator=(const Engimon& e){
	this->id = e.id;
	this->species = e.species;
	//this->skill = e.skill;
	elements = new string[MAX_ELEMENTS];
	this->elements[0] = e.elements[0];
	this->elements[1] = e.elements[1];
	this->slogan = e.slogan;
	this->maxExp = e.maxExp;
	this->numElements = e.numElements;
	this->setSymbol();
	return *this;
}

Engimon::~Engimon(){
	delete [] elements;
	//delete [] skill;
}

int Engimon::getId(){
	return id;
}

/*Skill& Engimon::getSkill(){
	return *skill; 
}*/

string& Engimon::getElement(){
	return *elements;
}

string Engimon::getSlogan(){
	return slogan;
}

char Engimon::getSymbol(){
	return symbol;
}

int Engimon::getMaxExp(){
	return maxExp;
}

string Engimon::getSpecies(){
	return species;
}

void Engimon::addElements(string _element){
	elements[numElements] = _element;
	numElements++;
	setSymbol();
}

void Engimon::setSymbol(){
	if(elements[0] == "Fire"){
		if(elements[1] == "Electric"){
			symbol = 'L';
		} else {
			symbol = 'F';
		}
	} else if(elements[0] == "Water"){
		if(elements[1] == "Ice"){
			symbol = 'S';
		} else if(elements[1] == "Ground"){
			symbol = 'N';
		} else {
			symbol = 'W';
		}
	} else if(elements[0] == "Ice"){
		if(elements[1] == "Water"){
			symbol = 'S';
		} else {
			symbol = 'I';
		}
	} else if(elements[0] == "Ground"){
		if(elements[1] == "Water"){
			symbol = 'N';
		} else {
			symbol = 'G'; 
		}
	} else if(elements[0] == "Electric"){
		if(elements[1] == "Fire"){
			symbol = 'L';
		} else {
			symbol = 'E';
		}
	}
}

void Engimon::setSymbol(char _symbol){
	symbol = _symbol;
}
