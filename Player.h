#ifndef PLAYER_H
#define PLAYER_H

#include "Cell.hpp"

class Player{
	private:
		Cell coordinate;
		char currSymbol;
	public:
		Player();
		Player& operator=(const Player&);
		~Player();
		Cell getCoordinate();
		char getCurrCymbol();
		void setCoordinate(Cell);
		void setCoordinate(int, int);
		void setCurrSymbol(char);
};

#endif
