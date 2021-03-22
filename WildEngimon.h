#ifndef WILD_ENGIMON_H
#define WILD_ENGIMON_H

#include "Cell.hpp"
#include "Engimon.hpp"
#include <iostream>
#include <string>

#define CAPITAL_LEVEL 4

class WildEngimon : public Engimon{
	private:
		Cell coordinate;
		int level;			
		int xp;				
		int cumulXp;		// Total xp engimon sekarang
	public:
		WildEngimon();
		WildEngimon(int, string, string, int, Cell, int, int);
		WildEngimon(const WildEngimon&);
		WildEngimon& operator=(const WildEngimon&);
		~WildEngimon();
		Cell getCoordinate();
		int getLevel();
		int getXp();
		int getCumulXp();
		void setCoordinate(Cell);
		void setCoordinate(int, int);
		void setLevel(int);
		void setXp(int);
		void xpUp(int);
		void levelUp(int);			
		bool isSuitable(Cell);
		void setSymbolLevel();
};

#endif
