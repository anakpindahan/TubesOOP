#include "Engimon.hpp"
#include <iostream>
using namespace std;

Engimon::Engimon() {
	id = -1;
	species = "-";
	slogan = "-";
//	skill = new Skill[MAX_SKILL];
	numElements = 0;
	elements = new string[MAX_ELEMENTS];
	elements[0] = "Fire";
	maxExp = 0;
	symbol = '/';
	setSymbol();
	numSkill = 0;
}

Engimon::Engimon(const Engimon& e) {
	id = e.id;
	species = e.species;
	slogan = e.slogan;
	elements = new string[MAX_ELEMENTS];
	elements[0] = e.elements[0];
	elements[1] = e.elements[1];
	skill = e.skill;
	/*	skill = new Skill[MAX_SKILL];
	 for(int i = 0; i < MAX_SKILL; i++){
	 skill[i] = e.skill[i];
	 }*/
	maxExp = e.maxExp;
	symbol = e.symbol;
	numElements = e.numElements;
	numSkill = 0;
}

Engimon::Engimon(int _id, string _species, string _slogan, int _maxExp) {
	id = _id;
	species = _species;
	slogan = _slogan;
	numElements = 0;
	elements = new string[MAX_ELEMENTS];
	maxExp = _maxExp;
	setSymbol();
	numElements = 0;
}

Engimon& Engimon::operator=(const Engimon& e) {
	this->id = e.id;
	this->species = e.species;
	this->skill = e.skill;
	elements = new string[MAX_ELEMENTS];
	this->elements[0] = e.elements[0];
	this->elements[1] = e.elements[1];
	this->slogan = e.slogan;
	this->maxExp = e.maxExp;
	this->numElements = e.numElements;
	this->setSymbol();
	skill = e.skill;
	numSkill = skill.size();
	return *this;
}

Engimon::~Engimon() {
	delete[] elements;
}

int Engimon::getId() {
	return id;
}

string Engimon::getElement(int i) {
	return elements[i];
}

string Engimon::getSlogan() {
	return slogan;
}

char Engimon::getSymbol() {
	return symbol;
}

int Engimon::getMaxExp() {
	return maxExp;
}

string Engimon::getSpecies() {
	return species;
}

void Engimon::addElements(string _element) {
	elements[numElements] = _element;
	numElements++;
	setSymbol();
}

void Engimon::setSymbol() {
	if (elements[0] == "Fire") {
		if (elements[1] == "Electric") {
			symbol = 'L';
		} else {
			symbol = 'F';
		}
	} else if (elements[0] == "Water") {
		if (elements[1] == "Ice") {
			symbol = 'S';
		} else if (elements[1] == "Ground") {
			symbol = 'N';
		} else {
			symbol = 'W';
		}
	} else if (elements[0] == "Ice") {
		if (elements[1] == "Water") {
			symbol = 'S';
		} else {
			symbol = 'I';
		}
	} else if (elements[0] == "Ground") {
		if (elements[1] == "Water") {
			symbol = 'N';
		} else {
			symbol = 'G';
		}
	} else if (elements[0] == "Electric") {
		if (elements[1] == "Fire") {
			symbol = 'L';
		} else {
			symbol = 'E';
		}
	}
}

void Engimon::setSymbol(char _symbol) {
	symbol = _symbol;
}

bool Engimon::isSameType(Engimon e) {
	if (numElements == e.numElements) {
		if (numElements == 1) {
			return (elements[0] == e.elements[0]);
		} else {
			return ((elements[0] == e.elements[0]
					&& elements[1] == e.elements[1])
					|| (elements[0] == e.elements[1]
							&& elements[1] == e.elements[0]));
		}
	} else {
		return false;
	}
}

void Engimon::addSkill(Skill a) {
	skill.push(a);
}

priority_queue<Skill> Engimon::getSkill() {
	return skill;
}

void Engimon::inheritSkill(Engimon e1, Engimon e2) {
	priority_queue<Skill> p1;
	priority_queue<Skill> p2;
	p1 = e1.skill;
	p2 = e2.skill;
	while (skill.size() < MAX_SKILL && p1.size() > 0 && p2.size()) {
		Skill s1 = p1.top();
		Skill s2 = p2.top();
		if (s1 < s2) {
			if (s2.canUsedBy(elements[0])
					|| s2.canUsedBy(elements[1])) {
				skill.push(s2);
			}
			p2.pop();
		} else {
			if (s1.canUsedBy(elements[0])
					|| s1.canUsedBy(elements[1])) {
				skill.push(s1);
			}
			p1.pop();
		}
	}
	while (skill.size() < MAX_SKILL && (p1.size() > 0 || p2.size())) {
		if (p1.size() > 0) {
			Skill s1 = p1.top();
			if (s1.canUsedBy(elements[0])
					|| s1.canUsedBy(elements[1])) {
				skill.push(s1);
			}
			p1.pop();
		} else {
			Skill s2 = p2.top();
			if (s2.canUsedBy(elements[0])
					|| s2.canUsedBy(elements[1])) {
				skill.push(s2);
			}
			p2.pop();
		}
	}

	numSkill = skill.size();

}

void Engimon::inheritElement(Engimon e1, Engimon e2) {
	if (e1.isSameType(e2)) {
		addElements(e1.elements[0]);
	} else if ((e1.elements[0] == "Fire" && e2.elements[0] == "Electric")
			|| (e1.elements[0] == "Electric" && e2.elements[0] == "Fire")
			|| (e1.elements[0] == "Water" && e2.elements[0] == "Ground")
			|| (e1.elements[0] == "Ground" && e2.elements[0] == "Water")
			|| (e1.elements[0] == "Water" && e2.elements[0] == "Ice")
			|| (e1.elements[0] == "Ice" && e2.elements[0] == "Water")) {
		addElements(e1.elements[0]);
		addElements(e2.elements[0]);
	} else {
		if (e1.elements[0] == "Fire") {
			if (e2.elements[0] == "Ice") {
				addElements(e1.elements[0]);
			} else {
				addElements(e2.elements[0]);
			}
		} else if (e1.elements[0] == "Water") {
			if (e2.elements[0] == "Fire") {
				addElements(e1.elements[0]);
			} else {
				addElements(e2.elements[0]);
			}
		} else if (e1.elements[0] == "Electric") {
			if (e2.elements[0] == "Water" || e2.elements[0] == "Ice") {
				addElements(e1.elements[0]);
			} else {
				addElements(e2.elements[0]);
			}
		} else if (e1.elements[0] == "Ground") {
			if (e2.elements[0] == "Fire" || e2.elements[0] == "Electric") {
				addElements(e1.elements[0]);
			} else {
				addElements(e2.elements[0]);
			}
		} else if (e1.elements[0] == "Ice") {
			if (e2.elements[0] == "Ground") {
				addElements(e1.elements[0]);
			} else {
				addElements(e2.elements[0]);
			}
		}
	}
}

int Engimon::getNumElements(){
	return numElements;
}

int Engimon::getNumSkill(){
	return numSkill;
}
