#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Cell.hpp"
#include "WildEngimon.h"
#include "Player.h"

#define MAP_X 20
#define MAP_Y 20
#define SEA_X 12
#define SEA_Y 12
#define MAX_WILD 10

class GameState{
	private:
		Player player;
		Cell map[MAP_Y][MAP_X];
		WildEngimon wildEngimons[MAX_WILD];
	public:
		GameState();
		void showMap();
		void movePlayer();
		string readCommand();
		void executeCommand(string);
};

#endif
