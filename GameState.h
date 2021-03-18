#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Cell.hpp"
#include "WildEngimon.h"
#include "Player.h"

class GameState{
	private:
		Player player;
		Cell map[20][20];
		WildEngimon wildEngimons[10];
	public:
		GameState();
		~GameState();
		void executeCommand();
};

#endif
