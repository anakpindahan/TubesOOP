#ifndef INVENTORY_SKILL
#define INVENTORY_SKILL

#include <iostream>
#include <iterator>
#include <map>
#include "Skill.hpp"
#include "Engimon.hpp"

#define SKILL_COUNT 20		

using namespace std;

class InventorySkill {
	private:
        map<Skill, int> inventorySkill;
        Skill listSkills[SKILL_COUNT];	
    public:
        InventorySkill();
        InventorySkill(int);
        //InventorySkill& operator=(const InventorySkill&);
		virtual ~InventorySkill();
        void initSkill();	

        void printInventorySkill();
        Skill nameToSkill(string);
        void learn(string, string);
        void addItem(string);
        void replaceSkill(Engimon, Skill);
        void useItem(string);
        int numOfElement();
};

#endif
