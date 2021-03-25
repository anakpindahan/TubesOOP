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
		InventoryEngimon<RealEngimon> inventoryEngimon;

	public:
		Player();
		Player& operator=(const Player&);
		~Player();
		Cell getCoordinate();
		char getCurrCymbol();
		InventoryEngimon<RealEngimon>& getInventoryEngimon();
		void setCoordinate(Cell);
		void setCoordinate(int, int);
		void setCurrSymbol(char);
		void setEngimon(RealEngimon);
		void addEngimon(RealEngimon);

};

#endif
