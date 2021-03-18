#ifndef PLAYER_H
#define PLAYER_H

#include "Cell.hpp"

class Player{
	private:
		Cell coordinate;
	public:
		Player();
		Player(const Player&);
		Player& operator=(const Player&);
		~Player();
		Cell getCoordinate();
		void setCoordinate(Cell);
};

#endif
