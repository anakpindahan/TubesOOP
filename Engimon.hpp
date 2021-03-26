#ifndef ENGIMON_H
#define ENGIMON_H
#include "Cell.hpp"
#include "Exception.hpp"
#include "Skill.hpp"
#include <iostream>
#include <queue>
using namespace std;

#define MAX_ELEMENTS 2
#define MAX_SKILL 4

class Engimon{
	protected:
		int id;				
		string species;		
		priority_queue<Skill> skill;
		string *elements;	// Bertipe list. Elemen bisa berupa "Fire", "Ground", "Electric", "Water", "Ice"
		string slogan;		// Slogan dari engimon (untuk 3.c.iv)
		int maxExp;			// Exp (kumulatif) maksimal yang dapat dimiliki engimon sebelum mati
		char symbol;		// Simbol dari engimon (default: kapital) di peta
		int numElements; 	// Banyak elemen yang dimiliki engimon
		int numSkill;
	public:
		Engimon();
		Engimon(const Engimon&);
		Engimon(int, string, string, int);
		Engimon& operator=(const Engimon&);
		~Engimon();
		int getId();
		priority_queue<Skill> getSkill();
		int hasSkill(priority_queue<Skill>, Skill);		// Return 0 kalau engimon tidak punya skill tsb
									// 1 kalau mastery levelnya >
									// 2 kalau sama
									// 3 kalau <
		string getElement(int);
		string getSlogan();
		char getSymbol(); 
		int getMaxExp();
		string getSpecies();
		void addElements(string);	// Menambahkan elemen dari engimon
		void setSymbol(); 			// Mengatur simbol dari engimon berdasarkan elemen
		void setSymbol(char);
		bool isSameType(Engimon);
		void addSkill(Skill);
		void removeSkill(string);
		void inheritSkill(Engimon, Engimon);		// Mewariskan skill yang sesuai dari orangtua
		void inheritElement(Engimon, Engimon);
		int getNumElements();
		int getNumSkill();
		void setId(int id);
		void setMaxExp(int maxExp);
		void setSlogan(const string& slogan);
		void setSpecies(const string& species);
};

#endif
