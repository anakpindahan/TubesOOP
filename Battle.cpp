#include <iostream>
#include <cmath>
#include "Battle.hpp"
using namespace std;
//BATTLE DI TARO DI PLAYER, MAXXP
Battle::Battle() : RealEngimon::RealEngimon(){
	totalPower = 0;
	elementAdvPlayer = 0;
	elementAdvEnemy = 0;
}

int Battle::sum(int num){
	if (num != 0){
		return num + sum(num-1);
	}
	else{
		return num;
	}
}

int Battle::TotalPower(RealEngimon w, int elementAdv, Skill s){
	return w.getLevel() * elementAdv + sum(s.getBasePower() * s.getMasteryLevel());
}

void Battle::showTotalPower(int total, int tag){
	if(tag == 0){ /* Player */
		cout << "My Total Power\t: " << total << endl;
	}
	else if(tag == 1){
		cout << "Enemy Total Power\t: " << total << endl;
	}
}

void Battle::elementAdv1(Engimon e1, Engimon e2){
	double matriks[5][5] = {{1, 0, 1, 0.5, 2},
								{2, 1, 0, 1, 1},
								{1, 2, 1, 0, 1.5},
								{1.5, 1, 2, 1, 0},
								{0, 1, 0.5, 2, 1}};
								
	if (e1.getNumElements() == 1 || e2.getNumElements() == 1){
		int elementAdv, i, j;
		if (e1.getElement(e1.getNumElements()) == "Fire"){i = 0;}
		else if (e1.getElement(e1.getNumElements()) == "Water"){i = 1;}
		else if (e1.getElement(e1.getNumElements()) == "Electric"){i = 2;}
		else if (e1.getElement(e1.getNumElements()) == "Ground"){i = 3;}
		else if (e1.getElement(e1.getNumElements()) == "Ice"){i = 4;}
		
		if (e2.getElement(e2.getNumElements()) == "Fire"){j = 0;}
		else if (e2.getElement(e2.getNumElements()) == "Water"){j = 1;}
		else if (e2.getElement(e2.getNumElements()) == "Electric"){j = 2;}
		else if (e2.getElement(e2.getNumElements()) == "Ground"){j = 3;}
		else if (e2.getElement(e2.getNumElements()) == "Ice"){j = 4;}
		
		elementAdvPlayer = matriks[i][j];
		elementAdvEnemy = matriks[j][i];
	}
	//else if (e1.getNumElements() == MAX_ELEMENTS || e2.getNumElements() == MAX_ELEMENTS){
	// yg 2 elemen belommm
}

void Battle::tanding(RealEngimon w1, RealEngimon w2, Skill s1, Skill s2){
	int totalPowerPlayer, totalPowerEnemy;
	
	// Hitung total power level
	totalPowerPlayer = TotalPower(w1, elementAdvPlayer, s1);
	totalPowerEnemy = TotalPower(w2, elementAdvPlayer, s2);
	
	//Tampilkan total power Level
	showTotalPower(totalPowerPlayer,0);
	showTotalPower(totalPowerEnemy,1);
	
	if (totalPowerPlayer < totalPowerEnemy){
		cout << "you lose" << endl;
	}
	else{
		//tambah ke inventory
		int exp = 200 + w1.getXp();
		string skill = s2.getSkillElements();
	}
}






