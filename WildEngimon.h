#ifndef WILD_ENGIMON_H
#define WILD_ENGIMON_H

#include "Cell.hpp"

class WildEngimon{
	private:
		int id;
		Cell coordinate;
		int level;
		int xp;
	public:
		WildEngimon();
		WildEngimon(int, Cell, int, int);
		WildEngimon(const WildEngimon&);
		WildEngimon& operator=(const WildEngimon&);
		~WildEngimon();
		int getId();
		Cell getCoordinate();
		int getLevel();
		int getXp();
		void setId(int);
		void setCoordinate(Cell);
		void setLevel(int);
		void setXp(int);
};

#endif
