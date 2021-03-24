#include "GameState.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	char input;
	string inp;
	cout << "Apakah Anda ingin memmasukkan map? (Y/n)";
	cin >> input;
	if (input == 'Y') {
		cout << "Silahkan masukkan nama file map:";
		cin >> inp;
		GameState newGame(inp);
		while (true) {
			newGame.showMap();
			try {
				newGame.executeCommand(newGame.readCommand());
			} catch (Exception e) {
				e.displayMessage();
			}
		}
	} else if(input == 'n'){
		GameState newGame;
		while (true) {
			newGame.showMap();
			try {
				newGame.executeCommand(newGame.readCommand());
			} catch (Exception e) {
				e.displayMessage();
				if(e.getErrorNumber() == EXIT_COMMAND){
					break;
				}
			}
		}
	} else {
		Exception(WRONG_COMMAND).displayMessage();
	}

	return 0;
}
