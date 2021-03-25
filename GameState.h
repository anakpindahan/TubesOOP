#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Cell.hpp"
#include "Player.h"
#include "Skill.hpp"
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "RealEngimon.h"
#include "Battle.hpp"

#define MAP_BARIS 20
#define MAP_KOLOM 20
#define SEA_X 12
#define SEA_Y 12
#define MAX_WILD 16				// Banyak engimon liar maksimal dalam satu ronde
#define ENGIMON_COUNT 12		// Banyak jenis engimon di katalog
#define SKILL_COUNT 20			// Banyak jenis Skill di Katalog
#define MOVE_ROUND 5 			// Lama ronde sampai engimon liar bergerak
#define SPAWN_ROUND 7 			// Lama ronde sampai menghasilkan memunculkan engimon lia baru
#define START_ENGIMON 3			// Banyak engimon yang diberi di awal

class GameState{
	private:
		Engimon listEngimons[ENGIMON_COUNT];		// Katalog engimon
		Skill listSkills[SKILL_COUNT];				// Katalog Skill
		Player player;
		int baris;
		int kolom;
		Cell** map;
		RealEngimon wildEngimons[MAX_WILD];			// Engimon liar yang ada
		int round;									// Untuk mencatat kapan harus spawn engimn liar lagi
													// dan mengatur pergerakan engimon liar
		int wildCount;								// Banyak engimon liar yang ada
		int playerEngimon;							// Banyak engimon player di inventory
	public:
		GameState();								// Membuat map secara acak
		GameState(string);							// Membuat map berdasarkan masukan pengguna
		void initEngimon();							// Buat katalog engimon 
		void initSkill();							// Buat katalog skill
		void readMap(string);								// Membaca masukan peta
		void showMap();								// Menuliskan posisi pemain dan peta ke layar
		void movePlayer();							
		void moveWildEngimons();
		void breedPlayerEngimons();
		void battlePlayerEngimon();
		string readCommand();
		void executeCommand(string);
		void spawn(int);							// Menspawn engimon liar baru
		bool valid(Cell);							// Mengecek apakah sebuah koordinat valid
		bool valid(int, int);
		void regenerateWildEngimons();
		int searchIdEngimon(RealEngimon);
		int searchIdEngimon(char);
		int searchIdWildEngimon(Cell);
};

#endif
