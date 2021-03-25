#include <iostream>
#include <cmath>
#include "Battle.hpp"
using namespace std;
//BATTLE DI TARO DI PLAYER, MAXXP
Battle::Battle() : WildEngimon::WildEngimon(){
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

int Battle::TotalPower(WildEngimon w, int elementAdv, Skill s){
	return w.getLevel() * elementAdv + sum(s.getBasePower() * s.getMasteryLevel());
}

void Battle::showTotalPower(){
	cout << "Total Power : " << totalPower << endl;
}

void Battle::elementAdv1(Engimon e1, Engimon e2){
	int elementAdv, i, j;
	string nama;
	double matriks[5][5] = {{1, 0, 1, 0.5, 2},
							{2, 1, 0, 1, 1},
							{1, 2, 1, 0, 1.5},
							{1.5, 1, 2, 1, 0},
							{0, 1, 0.5, 2, 1}};

	if (e1.getElement(1) == "Fire"){i = 0;}
	else if (e1.getElement(1) == "Water"){i = 1;}
	else if (e1.getElement(1) == "Electric"){i = 2;}
	else if (e1.getElement(1) == "Ground"){i = 3;}
	else if (e1.getElement(1) == "Ice"){i = 4;}
	
	if (e2.getElement(1) == "Fire"){j = 0;}
	else if (e2.getElement(1) == "Water"){j = 1;}
	else if (e2.getElement(1) == "Electric"){j = 2;}
	else if (e2.getElement(1) == "Ground"){j = 3;}
	else if (e2.getElement(1) == "Ice"){j = 4;}
	
	elementAdvPlayer = matriks[i][j];
	elementAdvEnemy = matriks[j][i];
}

void Battle::tanding(WildEngimon w1, WildEngimon w2, Skill s1, Skill s2){
	int totalPowerPlayer, totalPowerEnemy;
	totalPowerPlayer = TotalPower(w1, elementAdvPlayer, s1);
	totalPowerEnemy = TotalPower(w2, elementAdvPlayer, s2);
	if (totalPowerPlayer < totalPowerEnemy){
		cout << "Kamu Mati" << endl;
	}
	else{
		//tambah ke inventory
		int exp = 200 + w1.getXp();
		string skill = s2.getSkillElements();
	}
}






