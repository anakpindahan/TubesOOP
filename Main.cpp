#include "GameState.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	char input;
	string inp;
	cout << "Apakah Anda ingin memmasukkan map? (Y/n)";
	cin >> input;
	if(input == 'Y'){
		cout << "Silahkan masukkan nama file map:";
		cin >> inp;
		GameState newGame(inp);
		while(true){
			newGame.showMap();
			newGame.executeCommand(newGame.readCommand());
		}
	} else {
		GameState newGame;
		while(true){
			newGame.showMap();
			newGame.executeCommand(newGame.readCommand());
		}				
	}

	
	return 0;
}
