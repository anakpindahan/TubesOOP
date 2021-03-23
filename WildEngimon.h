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
		string name;
		string parentName1;
		string parentName2;
		string speciesParent1;
		string speciesParent2;
	public:
		WildEngimon();
		WildEngimon(int, string, string, int, Cell, int, int, string);
		WildEngimon(const WildEngimon&);
		WildEngimon& operator=(const WildEngimon&);
		~WildEngimon();
		Cell getCoordinate();
		int getLevel();
		int getXp();
		int getCumulXp();
		string getName();
		string getParentName1();
		string getParentName2();
		string getSpeciesParent1();
		string getSpeciesParent2();
		void setCoordinate(Cell);
		void setCoordinate(int, int);
		void setLevel(int);
		void setXp(int);
		void setName(string);
		void setParentName1(string);
		void setParentName2(string);
		void setSpeciesParent1(string);
		void setSpeciesParent2(string);
		void xpUp(int);
		void levelUp(int);			
		bool isSuitable(Cell);
		void setSymbolLevel();
		WildEngimon breed(WildEngimon);					// Dua metode ini sebenarnya untuk Engimon di inventory
		bool legalToBreed(WildEngimon, WildEngimon);	// Akan dipindah jika sudah ada
};

#endif
