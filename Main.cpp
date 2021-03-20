#include "GameState.h"
#include <iostream>
using namespace std;

int main(){
	GameState newGame;
	while(true){
		newGame.showMap();
		newGame.executeCommand(newGame.readCommand());
	}		
	
	return 0;
}
