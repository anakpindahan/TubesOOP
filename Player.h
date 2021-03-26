#ifndef PLAYER_H
#define PLAYER_H

#include "Cell.hpp"
#include "Engimon.hpp"
#include "InventoryEngimon.hpp"
#include "InventorySkill.hpp"

class Player{
	private:
		Cell coordinate;
		Cell prevCoordinate;
		char currSymbol;
		InventoryEngimon<RealEngimon> inventoryEngimon;
		InventorySkill inventorySkill;
		int activeEngimonId;
		RealEngimon engimon;
	public:
		Player();
		Player& operator=(const Player&);
		~Player();
		Cell getCoordinate();
		Cell getPrevCoordinate();
		char getCurrCymbol();
		Cell getEngimonCoordinate();
		InventoryEngimon<RealEngimon>& getInventoryEngimon();
		int getActiveEngimon();
		void setCoordinate(Cell);
		void setCoordinate(int, int);
		void setEngimonCoordinate(int, int);
		void setPrevCoordinate(Cell);
		void setPrevCoordinate(int, int);
		void setCurrSymbol(char);
		void setActiveEngimon(int);
		void setEngimon(RealEngimon);
		void addEngimon(RealEngimon);
		void addSkill(string);
		void useSkill(string);
		InventorySkill& getInventorySkill();
		void interact();
};

#endif
