#ifndef PLAYER_H
#define PLAYER_H

#include "Cell.hpp"
#include "Engimon.hpp"
#include "InventoryEngimon.hpp"

class Player{
	private:
		Engimon engimon;
		Cell coordinate;
		char currSymbol;
		InventoryEngimon<Engimon> inventoryEngimon;

	public:
		Player();
		Player& operator=(const Player&);
		~Player();
		Cell getCoordinate();
		char getCurrCymbol();
		void setCoordinate(Cell);
		void setCoordinate(int, int);
		void setCurrSymbol(char);
		void setEngimon(Engimon);
};

#endif
