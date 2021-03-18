#include "GameState.h"
#include <iostream>

using namespace std;

GameState::GameState(){
	Player player;
	int i, j;
	Cell map[20][20];
	for(i = 0; i < 20; i++){
		for(j = 0; j < 20; j++){
			if(i > 12 && j > 12){
				map[i][j] = Cell(i, j, "Grass");				
			} else {
				map[i][j] = Cell(i, j, "Sea");
			}
		}
	}
	WildEngimon wildEngimons[10];
	wildEngimons[0] =  WildEngimon(1, map[3][4], 2, 205);
}

GameState::~GameState(){

}

void GameState::executeCommand(){
	cout << "Hello" << endl;
}
