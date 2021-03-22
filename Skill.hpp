#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <string>
using namespace std;

#define MAX_EL_SKILL 4

class Skill{
	private:
		int basePower;
		int masteryLevel;
		string *elements;
	public:
		Skill();
		Skill(int, int, string&);
		Skill& operator=(const Skill&);
		~Skill();
		int getBasePower();
		int getMasteryLevel();
		string& getElements();
};

#endif
