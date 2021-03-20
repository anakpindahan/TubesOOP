#include "GameState.h"
#include <iostream>

using namespace std;

GameState::GameState(){
	// Membuat map
	int i, j;
	for(i = 0; i < MAP_Y; i++){
		for(j = 0; j < MAP_X; j++){
			if(i < SEA_Y && j > SEA_X){
				map[i][j].setX(i);
				map[i][j].setY(j);
				map[i][j].setType("Sea");			
			} else {
				map[i][j].setX(i);
				map[i][j].setY(j);
				map[i][j].setType("Grass");
			}
		}
	}
	
	Player player;
	map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity("Player");
}

/*
void GameState::executeCommand(Command command){
	if(command.getCommandType() == "Move"){
		if(command.getDirection() == "W"){
			map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity("Air");
			player.setCoordinate(player.getCoordinate().getX() - 1, player.getCoordinate().getY());
			map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity("Player");
		} else if(command.getDirection() == "S"){
			map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity("Air");
			player.setCoordinate(player.getCoordinate().getX() + 1, player.getCoordinate().getY());
			map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity("Player");
		} else if(command.getDirection() == "D"){
			map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity("Air");
			player.setCoordinate(player.getCoordinate().getX(), player.getCoordinate().getY() + 1);
			map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity("Player");
		} else if(command.getDirection() == "A"){
			map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity("Air");
			player.setCoordinate(player.getCoordinate().getX(), player.getCoordinate().getY() - 1);
			map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity("Player");
		}
	} else {
		cout << "No, not like this" << endl;
	}
}
*/
void GameState::showMap(){
	int i, j;
	for(i = 0; i < MAP_Y; i++){
		for(j = 0; j < MAP_X - 1; j++){
			cout << map[i][j];
		}
		cout << map[i][MAP_X - 1] << endl;
	}
}
/*
Command GameState::setCommand(){
	string _command;
	cout << "Silahkan masukkan command pilihan Anda" << endl;
	cin >> _command;
	if(_command == "Move"){
		string _direction;
		cout << "Silahkan masukan arah yang Anda inginkan" << endl;
		cin >> _direction;
		MoveCommand moveCommand(_direction);
		return moveCommand;
	}
}*/

void GameState::movePlayer(){
	string direction;
	cout << "Silakan masukkan command yang ingin dilakukan" << endl;
	cin >> direction;
	
	int i = player.getCoordinate().getX(), j = player.getCoordinate().getY(), k, l;
	if(direction == "W"){
		k = i - 1;
		l = j;
	} else if(direction == "S"){
		k = i + 1;
		l = j;
	} else if(direction == "A"){
		k = i;
		l = j - 1;
	} else if(direction == "D"){
		k = i;
		l = j + 1;
	} else {
		k = i;
		l = j;
	}
	map[i][j].setEntity("Air");
	player.setCoordinate(k, l);
	map[k][l].setEntity("Player");
}

string GameState::readCommand(){
	string _command;
	cout << "Silahkan masukkan command pilihan Anda" << endl;
	cin >> _command;
	return _command;
}

void GameState::executeCommand(string _command){
	if(_command == "Move"){
		movePlayer();
	}
}
