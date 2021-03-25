#ifndef INVENTORY_H
#define INVENTORY_H

//#ifndef INVENTORYSKILL_H
//#define INVENTORYSKILL_H

#include <iostream>
#include <iterator>
#include <map>
#include "Skill.hpp"
#include "Engimon.hpp"

using namespace std;

class Inventory {
	private:
		int capacity;
        map<Skill, int> inventorySkill;
    
    public:
        Inventory();
        Inventory(int);
        Inventory& operator=(const Inventory&);
		virtual ~Inventory();
        int getMaxCapacity();
        void setMaxCapacity(int);
        void printInventory();
        Skill nameToSkill(string);
        void learn(string, string);
        void addItem(string);
        void replaceItem();
        void useItem(string);
};

#endif