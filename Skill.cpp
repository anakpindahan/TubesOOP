#include "Skill.hpp"
#include <iostream>

using namespace std;

Skill::Skill(){
    namaSkill = "noName";
    skillElements = new string[MaxSkillElements];
    for (int i = 0; i<MaxSkillElements; i++){
    	skillElements[i] = "noElement";
	}
    basePower = 1;
    masteryLevel = 1;
    numSkill = 0;
}

Skill::Skill(string nama, int BP, int ML){
    namaSkill = nama;
    basePower = BP;
    masteryLevel = ML;
    
    skillElements = new string[MaxSkillElements];
    for (int i = 0; i<MaxSkillElements; i++){
    	skillElements[i] = "noElement";
	}
    numSkill = 0;
}

Skill::Skill(const Skill& s){
	namaSkill = s.namaSkill;
	basePower = s.basePower;
	masteryLevel = s.masteryLevel;

	skillElements = new string[MaxSkillElements];
	for(int i = 0; i < MaxSkillElements; i++){
		skillElements[i] = s.skillElements[i];
	}
	numSkill = s.numSkill;
}

Skill& Skill::operator=(const Skill& s){
	namaSkill = s.namaSkill;
	basePower = s.basePower;
	masteryLevel = s.masteryLevel;
	for (int i=0; i<MaxSkillElements; i++){
		skillElements[i] = s.skillElements[i];
	}
	numSkill = s.numSkill;
	return *this;
}

Skill::~Skill(){
	delete[] skillElements;
}

string Skill::getNamaSkill() const{
	return namaSkill;
} 

int Skill::getBasePower(){
	return basePower;
}

int Skill::getMasteryLevel(){
	return masteryLevel;
}

string& Skill::getSkillElements(){
	return *skillElements;
}


void Skill::setNamaSkill(string nama){
	namaSkill = nama;
}

void Skill::addSkillElements(string element){ //asumsi element skill yang ada di file eksternal tidak lebih dari 5.
	int i = 0;
	while (skillElements[i] != "noElement"){
		i++;
	}
	skillElements[i] = element;
}

void Skill::setBasePower(int BP){
	basePower = BP;
}

void Skill::addMasteryLevel(int a){
	masteryLevel += a;
}

bool Skill::operator <(const Skill& s) const{
	return (masteryLevel < s.masteryLevel);
}

bool Skill::operator >(const Skill& s) const {
	return (masteryLevel > s.masteryLevel);
}

bool Skill::operator ==(const Skill& s) const {
	return (masteryLevel == s.masteryLevel);
}

bool Skill::canUsedBy(string element) {
	bool temp = false;
	for(int i = 0; i < MaxSkillElements; i++){
		if(skillElements[i] == element){
			temp = true;
		}
	}
	return temp;
}

ostream& operator<<(ostream& out, const Skill& skill){
	out << "Nama skill: " << skill.namaSkill << endl;
	out << "       Base power: " << skill.basePower << endl;
	out << "       Mastery level: " << skill.masteryLevel << endl;
	out << "       Elemen yang dapat menggunakan skill: ";
	for(int i = 0; i < skill.numSkill; i++){
		out << skill.skillElements[i] << " ";
	}
	return out;
}
