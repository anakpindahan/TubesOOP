#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Cell.hpp"
#include "WildEngimon.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include <fstream>

#define MAP_BARIS 20
#define MAP_KOLOM 20
#define SEA_X 12
#define SEA_Y 12
#define MAX_WILD 16				// Banyak engimon liar maksimal dalam satu ronde
#define ENGIMON_COUNT 12		// Banyak jenis engimon di katalog
#define MOVE_ROUND 5 			// Lama ronde sampai engimon liar bergerak
#define SPAWN_ROUND 7 			// Lama ronde sampai menghasilkan memunculkan engimon lia baru


class GameState{
	private:
		Engimon listEngimons[ENGIMON_COUNT];		// Katalog engimon
		Player player;
		int baris;
		int kolom;
		Cell** map;
		WildEngimon wildEngimons[MAX_WILD];			// Engimon liar yang ada
		int round;									// Untuk mencatat kapan harus spawn engimn liar lagi
													// dan mengatur pergerakan engimon liar
		int wildCount;								// Banyak engimon liar yang ada
	public:
		GameState();								// Membuat map secara acak
		GameState(string);							// Membuat map berdasarkan masukan pengguna
		void initEngimon();							// Buat katalog engimon 
		void readMap(string);								// Membaca masukan peta
		void showMap();								// Menuliskan posisi pemain dan peta ke layar
		void movePlayer();							
		void moveWildEngimons();
		string readCommand();
		void executeCommand(string);
		void spawn(int);							// Menspawn engimon liar baru
		bool valid(Cell);							// Mengecek apakah sebuah koordinat valid
		bool valid(int, int);
		void regenerateWildEngimons();
		int searchIdEngimon(WildEngimon);
		int searchIdEngimon(char);
};

#endif
