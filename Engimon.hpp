#ifndef ENGIMON_H
#define ENGIMON_H

#include "Cell.hpp"
#include "Exception.hpp"

#define MAX_ELEMENTS 2
#define MAX_SKILL 4

class Engimon{
	protected:
		int id;				
		string species;		
		// Skill *skill;
		string *elements;	// Bertipe list. Elemen bisa berupa "Fire", "Ground", "Electric", "Water", "Ice"
		string slogan;		// Slogan dari engimon (untuk 3.c.iv)
		int maxExp;			// Exp (kumulatif) maksimal yang dapat dimiliki engimon sebelum mati
		char symbol;		// Simbol dari engimon (default: kapital) di peta
		int numElements; 	// Banyak elemen yang dimiliki engimon
	public:
		Engimon();
		Engimon(const Engimon&);
		Engimon(int, string, string, int);
		Engimon& operator=(const Engimon&);
		~Engimon();
		int getId();
		//Skill& getSkill();
		string& getElement();
		string getSlogan();
		char getSymbol(); 
		int getMaxExp();
		string getSpecies();
		void addElements(string);	// Menambahkan elemen dari engimon
		void setSymbol(); 			// Mengatur simbol dari engimon berdasarkan elemen
		void setSymbol(char);
		bool isSameType(Engimon);
};

#endif
