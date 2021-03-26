#include <iostream>
#include <cmath>
#include "Battle.hpp"
using namespace std;
//BATTLE DI TARO DI PLAYER, MAXXP
Battle::Battle(){
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
		cout << "My Total Power\t\t: " << total << endl;
	}
	else if(tag == 1){
		cout << "Enemy Total Power\t: " << total << endl;
	}
}

void Battle::elementAdv1(Engimon e1, Engimon e2){
	int i, j;
	double matriks[5][5] = {{1, 0, 1, 0.5, 2},
								{2, 1, 0, 1, 1},
								{1, 2, 1, 0, 1.5},
								{1.5, 1, 2, 1, 0},
								{0, 1, 0.5, 2, 1}};

	if(e1.getNumElements() == 1 && e2.getNumElements() == 1){
		if (e1.getElement(e1.getNumElements()-1) == "Fire"){i = 0;}
		else if (e1.getElement(e1.getNumElements()-1) == "Water"){i = 1;}
		else if (e1.getElement(e1.getNumElements()-1) == "Electric"){i = 2;}
		else if (e1.getElement(e1.getNumElements()-1) == "Ground"){i = 3;}
		else if (e1.getElement(e1.getNumElements()-1) == "Ice"){i = 4;}

		if (e2.getElement(e2.getNumElements()-1) == "Fire"){j = 0;}
		else if (e2.getElement(e2.getNumElements()-1) == "Water"){j = 1;}
		else if (e2.getElement(e2.getNumElements()-1) == "Electric"){j = 2;}
		else if (e2.getElement(e2.getNumElements()-1) == "Ground"){j = 3;}
		else if (e2.getElement(e2.getNumElements()-1) == "Ice"){j = 4;}

		elementAdvPlayer = matriks[i][j];
		elementAdvEnemy = matriks[j][i];
	}

	if (e1.getNumElements() == MAX_ELEMENTS || e2.getNumElements() == MAX_ELEMENTS){
		int elementAdvPlayer2, elementAdvEnemy2;
		if (e1.getElement(e1.getNumElements()-1) == "Fire"){i = 0;}
		else if (e1.getElement(e1.getNumElements()-1) == "Water"){i = 1;}
		else if (e1.getElement(e1.getNumElements()-1) == "Electric"){i = 2;}
		else if (e1.getElement(e1.getNumElements()-1) == "Ground"){i = 3;}
		else if (e1.getElement(e1.getNumElements()-1) == "Ice"){i = 4;}
		
		if (e2.getElement(e2.getNumElements()-1) == "Fire"){j = 0;}
		else if (e2.getElement(e2.getNumElements()-1) == "Water"){j = 1;}
		else if (e2.getElement(e2.getNumElements()-1) == "Electric"){j = 2;}
		else if (e2.getElement(e2.getNumElements()-1) == "Ground"){j = 3;}
		else if (e2.getElement(e2.getNumElements()-1) == "Ice"){j = 4;}
		elementAdvPlayer2 = matriks[i][j];
		elementAdvEnemy2 = matriks[j][i];
		if (elementAdvPlayer2 >= elementAdvPlayer){
			elementAdvPlayer = elementAdvPlayer2;
		}
		if (elementAdvEnemy2 >= elementAdvEnemy){
			elementAdvEnemy = elementAdvEnemy2;
		}
	}
}

void Battle::tanding(Player& w1,int numEngimon, RealEngimon w2, Skill s1, Skill s2){
	int totalPowerPlayer, totalPowerEnemy;
	// Hitung total power level
	totalPowerPlayer = TotalPower(w1.getInventoryEngimon().getEngimon(numEngimon), elementAdvPlayer, s1);
	totalPowerEnemy = TotalPower(w2, elementAdvPlayer, s2);

	//Tampilkan total power Level
	showTotalPower(totalPowerPlayer,0);
	showTotalPower(totalPowerEnemy,1);
	
	if (totalPowerPlayer < totalPowerEnemy){
		cout << "\n T_T ---- you lose ---- T_T\n" << endl;
	}
	else{
		//tambah ke inventory
		//Menambahkan EXP
		int exp = 200 + w1.getInventoryEngimon().getEngimon(numEngimon).getXp();
		w1.getInventoryEngimon().getEngimon(numEngimon).setXp(exp);
		cout << endl<<"## Anda Mendapatkan tambahan EXP sebesar 200 ## " << endl;

		// Menambahkan Engimon hadiah
		w2.setStatus(PLAYER_ENGIMON);

		w1.addEngimon(w2);
		cout << "## Engimon Reward \t>>> " << w2.getSpecies() << endl;

		//Menambahkan Skill hadiah
		Skill skillReward;
		skillReward.operator=(GameState::generateSkill(w2));
		cout << "## Skill Reward \t>>> " << skillReward.getNamaSkill()  << endl;
	}

}






