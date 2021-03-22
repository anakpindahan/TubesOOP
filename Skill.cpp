#include "Skill.hpp"
#include <iostream>
using namespace std;

Skill::Skill(){
	basePower = 0;
	masteryLevel = 0;
}

Skill::Skill(int _basePower, int _masteryLevel, string& _elements){
	basePower = _basePower;
	masteryLevel = _masteryLevel;
	for(int i = 0; i < MAX_EL_SKILL; i++){
		elements[i] = _elements[i];
	}
}

Skill& Skill::operator=(const Skill& s){
	this->basePower = s.basePower;
	this->masteryLevel = s.masteryLevel;
	this->elements = s.elements;
	return *this;
}

Skill::~Skill(){
	
}

int Skill::getBasePower(){
	return basePower;
}

int Skill::getMasteryLevel(){
	return masteryLevel;
}

string& Skill::getElements(){
	return *elements;
}
