#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include "Skill.hpp"
#include "Engimon.hpp"
#include "RealEngimon.h"

using namespace std;

class Battle : public RealEngimon{
    private:
        int totalPower;
        int elementAdvPlayer;
        int elementAdvEnemy;

    public:
    	Battle();
    	int sum(int);
		int TotalPower(RealEngimon, int, Skill);
		void showTotalPower(int,int);
		void elementAdv1(Engimon, Engimon);
		void tanding(RealEngimon, RealEngimon, Skill, Skill);
        
};

#endif
