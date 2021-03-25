#ifndef REAL_ENGIMON_H
#define REAL_ENGIMON_H

#include "Cell.hpp"
#include "Engimon.hpp"
#include <iostream>
#include <string>

#define CAPITAL_LEVEL 4
#define WILD_ENGIMON 1
#define PLAYER_ENGIMON 2
#define ACTIVE_ENGIMON 3


class RealEngimon : public Engimon{
	private:
		Cell coordinate;
		int level;			
		int xp;				
		int cumulXp;		// Total xp engimon sekarang
		int status;
		string name;
		string parentName1;
		string parentName2;
		string speciesParent1;
		string speciesParent2;
	public:
		RealEngimon();
		RealEngimon(int, int, string, string, int, Cell, int, int, string);
		RealEngimon(const RealEngimon&);
		RealEngimon& operator=(const RealEngimon&);
		~RealEngimon();

		// Getter
		Cell getCoordinate();
		int getLevel();
		int getXp();
		int getCumulXp();
		string getName();
		string getParentName1();
		string getParentName2();
		string getSpeciesParent1();
		string getSpeciesParent2();
		int getStatus();

		// Setter
		void setCoordinate(Cell);
		void setCoordinate(int, int);
		void setLevel(int);
		void setXp(int xp);
		void setCumulXp(int);
		void setName(string);
		void setStatus(int);
		void setParentName1(string);
		void setParentName2(string);
		void setSpeciesParent1(string);
		void setSpeciesParent2(string);

		// Level
		void xpUp(int);
		void levelUp(int);

		// Move
		void setSymbolLevel();
		bool isSuitable(Cell);

		// Breed
		RealEngimon breed(RealEngimon);
		bool legalToBreed(RealEngimon, RealEngimon);

		// Tampilkan info
		void showStat();

};

#endif
