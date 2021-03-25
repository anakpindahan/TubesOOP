#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include "Skill.hpp"
#include "Engimon.hpp"
#include "WildEngimon.h"

using namespace std;

class Battle : public WildEngimon{
    private:
        int totalPower;
        int elementAdvPlayer;
        int elementAdvEnemy;

    public:
    	Battle();
    	int sum(int);
		int TotalPower(WildEngimon, int, Skill);
		void showTotalPower(int);
		void elementAdv1(Engimon, Engimon);
		void tanding(WildEngimon, WildEngimon, Skill, Skill);
        
};

#endif
