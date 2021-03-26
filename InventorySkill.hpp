#ifndef INVENTORY_SKILL
#define INVENTORY_SKILL

#include <iostream>
#include <iterator>
#include <map>
#include "Skill.hpp"
#include "Engimon.hpp"

using namespace std;

class InventorySkill {
	private:
        map<Skill, int> inventorySkill;
    public:
        InventorySkill();
        InventorySkill(int);
        //InventorySkill& operator=(const InventorySkill&);
		virtual ~InventorySkill();
        void printInventorySkill();
        Skill nameToSkill(string);
        void learn(string, string);
        void addItem(string);
        void replaceSkill(Engimon, Skill);
        void useItem(string);
        int numOfElement();
};

#endif
