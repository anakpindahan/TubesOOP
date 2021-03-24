#include "GameState.h"
#include <iostream>
#include <ctype.h>

using namespace std;

GameState::GameState() {
	// Inisialisasi map
	map = new Cell*[MAP_BARIS];
	for (int i = 0; i < MAP_BARIS; i++) {
		map[i] = new Cell[MAP_KOLOM];
	}

	// Membuat map
	int i, j;
	for (i = 0; i < MAP_BARIS; i++) {
		for (j = 0; j < MAP_KOLOM; j++) {
			if (i < SEA_Y && j > SEA_X) {
				map[i][j].setX(i);
				map[i][j].setY(j);
				map[i][j].setType("Sea");
				map[i][j].setSymbol('o');
			} else {
				map[i][j].setX(i);
				map[i][j].setY(j);
				map[i][j].setType("Grass");
				map[i][j].setSymbol('-');
			}
		}
	}
	baris = MAP_BARIS;
	kolom = MAP_KOLOM;

	// Membuat Player
	Player player;
	map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity(
			"Player");
	map[player.getCoordinate().getX()][player.getCoordinate().getY()].setSymbol(
			'P');

	srand(time(NULL));

	// Menmbuat list engimon
	initEngimon();

	// Menggenerate wild engimon

	wildCount = MAX_WILD - (rand() % 7);
	spawn(wildCount);

	// Mencatat round
	round = 1;
}

GameState::GameState(string _file) {
	cout << "Masukkan ukuran dari peta (Format: banyakBaris banyakKolom):";
	cin >> baris >> kolom;

	// Inisialisasi map
	map = new Cell*[baris];
	for (int i = 0; i < baris; i++) {
		map[i] = new Cell[kolom];
	}

	// Menmbuat list engimon
	initEngimon();

	// Membuat map
	readMap(_file);

	// Membuat Player
	Player player;
	map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity(
			"Player");
	map[player.getCoordinate().getX()][player.getCoordinate().getY()].setSymbol(
			'P');

	srand(time(NULL));

	// Menggenerate wild engimon

	wildCount = MAX_WILD - (rand() % 7);
	spawn(wildCount);

	// Mencatat round
	round = 1;

}

void GameState::readMap(string _file) {
	string mapSlice;
	ifstream mapFile(_file);
	int j = 0;
	while (mapFile >> mapSlice) {
		for (int i = 0; i < mapSlice.length(); i++) {
			map[j][i].setX(i);
			map[j][i].setY(j);
			map[j][i].setSymbol(mapSlice[i]);
			string entity;
			string type;
			if (mapSlice[i] == 'o') {
				entity = "Air";
				type = "Sea";
			} else if (mapSlice[i] == '-') {
				entity = "Air";
				type = "Grass";
			}
			map[j][i].setType(entity);
			map[j][i].setType(type);
		}
		j++;
	}

	mapFile.close();
}

void GameState::initEngimon() {
	listEngimons[0] = Engimon(1, "Charmeleon", "Cha cha real smooth", 10000);
	listEngimons[0].addElements("Fire");
	listEngimons[1] = Engimon(2, "Omanyte", "Ooo man ooo man", 30000);
	listEngimons[1].addElements("Water");
	listEngimons[2] = Engimon(3, "Doraemon", "Aku ini kucing, bukan musang",
			66000);
	listEngimons[2].addElements("Ice");
	listEngimons[3] = Engimon(4, "Pikachu", "Pika pika", 120000);
	listEngimons[3].addElements("Electric");
	listEngimons[4] = Engimon(5, "BoboiBoyGempa", "Terbaek", 35000);
	listEngimons[4].addElements("Ground");
	listEngimons[5] = Engimon(6, "LaCorona",
			"Siapa itu yang minta libur setahun?", 55500);
	listEngimons[5].addElements("Water");
	listEngimons[5].addElements("Ice");
	listEngimons[6] = Engimon(7, "Buzz", "Ah yes, the floor here made of floor",
			60000);
	listEngimons[6].addElements("Water");
	listEngimons[6].addElements("Ground");
	listEngimons[7] = Engimon(8, "Boot", "Boot boot boot", 80000);
	listEngimons[7].addElements("Fire");
	listEngimons[7].addElements("Electric");
	listEngimons[8] = Engimon(9, "AHHA", "Ashiaaaap", 55500);
	listEngimons[8].addElements("Electric");
	listEngimons[9] = Engimon(10, "DewiUseless", "Wheee, Kazumaaaa", 77800);
	listEngimons[9].addElements("Water");
	listEngimons[9].addElements("Ice");
	listEngimons[10] = Engimon(11, "YukiOnna", "Hurururururu", 88200);
	listEngimons[10].addElements("Ice");
	listEngimons[11] = Engimon(12, "Oopsie", "Ctor cctor dtor", 65000);
	listEngimons[11].addElements("Ground");
}

void GameState::showMap() {
	cout << "<<<<<<<<<<<<<<<<<<------------------------>>>>>>>>>>>>>>>>>>>" << endl;
	cout << "Engimon Ronde ke-" << round << endl;
	int i, j;
	for (i = 0; i < baris; i++) {
		for (j = 0; j < kolom - 1; j++) {
			cout << map[i][j];
		}
		cout << map[i][kolom - 1] << endl;
	}
	cout <<  endl;
	cout << "<<<<<<<<<<<<<<<<<<------------------------>>>>>>>>>>>>>>>>>>>" << endl;

}

void GameState::movePlayer() {
	string direction;
	cout << "Silakan masukkan arah pergerakan yang ingin dilakukan" << endl;
	cout << "Arah yang dapat diambil: A (kiri), S (bawah), W (atas), D(kanan)" << endl;
	cout << "Arah yang ingin diambil:";
	cin >> direction;

	int i = player.getCoordinate().getX(), j = player.getCoordinate().getY(), k,
			l;
	if (direction == "A") {
		k = i - 1;
		l = j;
	} else if (direction == "D") {
		k = i + 1;
		l = j;
	} else if (direction == "W") {
		k = i;
		l = j - 1;
	} else if (direction == "S") {
		k = i;
		l = j + 1;
	} else {
		k = i;
		l = j;
	}
	if (valid(k, l)) {
		if (valid(map[l][k])) {
			map[j][i].setEntity("Air");
			map[j][i].setSymbol(player.getCurrCymbol());
			player.setCoordinate(k, l);
			map[l][k].setEntity("Player");
			player.setCurrSymbol(map[l][k].getSymbol());
			map[l][k].setSymbol('P');
		} else {
			throw(Exception(OCCUPIED_CELL));
		}
	} else {
		throw(Exception(CELL_OUT_OF_RANGE));
	}

}

void GameState::moveWildEngimons() {
	for (int i = 0; i < wildCount; i++) {
		int k, l, m = wildEngimons[i].getCoordinate().getX(), n =
				wildEngimons[i].getCoordinate().getY();

		int randDir = rand() % 5;

		if (randDir == 0) {
			k = m - 1;
			l = n;
		} else if (randDir == 1) {
			k = m + 1;
			l = n;
		} else if (randDir == 2) {
			k = m;
			l = n - 1;
		} else if (randDir == 3) {
			k = m;
			l = n + 1;
		} else if (randDir == 4) {
			k = m;
			l = n;
		}
		if (valid(k, l)) {
			if (valid(map[l][k]) && wildEngimons[i].isSuitable(map[l][k])) {
				map[n][m].setEntity("Air");
				map[n][m].setNaturalSymbol();
				wildEngimons[i].setCoordinate(k, l);
				map[l][k].setEntity("WEng");
				map[l][k].setSymbol(wildEngimons[i].getSymbol());
			}
		}
	}
}

string GameState::readCommand() {
	string _command;
	cout << "Silahkan masukkan command pilihan Anda" << endl;
	cout << "Command yang dapat dimasukkan:" << endl;
	cout << "1. Move (untuk melakukan pergerakan)" << endl;
	cout << "2. Breed (untuk mengawinkan engimon)" << endl;
	cout << "3. Exit (untuk keluar dari permainan)" << endl;
	cout << "Command yang ingin dilakukan:";
	cin >> _command;
	return _command;
}

void GameState::executeCommand(string _command) {
	if (_command == "Move") {
		try {
			movePlayer();
			round++;
			regenerateWildEngimons();
		} catch (Exception e) {
			e.displayMessage();
		}
	} else if (_command == "Breed") {
		WildEngimon child;
		try {
			child = wildEngimons[0].breed(wildEngimons[1]);
			int i = searchIdEngimon(child) - 1;
			cout << "Masukkan nama bayi engimon: ";
			string _name;
			cin >> _name;
			child.setName(_name);
			round++;
			regenerateWildEngimons();
		} catch (Exception e) {
			e.displayMessage();
		}
	} else if(_command == "Exit"){
		throw(Exception(EXIT_COMMAND));
	} else {
		throw(Exception(WRONG_COMMAND));
	}
}

void GameState::spawn(int newWild) {
	int j = newWild;
	int i = 0;
	while (j > 0 && i < MAX_WILD) {

		// Cari indeks terkecil yang kosong
		if (wildEngimons[i].getId() <= 0) {
			Engimon e;

			// Pilih petak acak
			int y = rand() % baris;
			int x = rand() % kolom;
			char engSym;
			if (map[y][x].getType() == "Grass") {
				int r = rand() % 5;
				if (r == 0) {
					engSym = 'F';
				} else if (r == 1) {
					engSym = 'G';
				} else if (r == 2) {
					engSym = 'E';
				} else if (r == 3) {
					engSym = 'L';
				} else if (r == 4) {
					engSym = 'N';
				}
			} else {
				int r = rand() % 4;
				if (r == 0) {
					engSym = 'W';
				} else if (r == 1) {
					engSym = 'I';
				} else if (r == 2) {
					engSym = 'S';
				} else if (r == 3) {
					engSym = 'N';
				}
			}
			int idE = searchIdEngimon(engSym);

			e = listEngimons[idE - 1];
			wildEngimons[i] = WildEngimon(e.getId(), e.getSpecies(),
					e.getSlogan(), e.getMaxExp(), Cell(), rand() % 10,
					rand() % 100, "No Name");
			wildEngimons[i].setSymbol(e.getSymbol());
			wildEngimons[i].setSymbolLevel();
			wildEngimons[i].setCoordinate(x, y);
			map[y][x].setEntity("WEng");
			map[y][x].setSymbol(wildEngimons[i].getSymbol());
			j--;
		}
		i++;
	}
}

bool GameState::valid(Cell c) {
	return (c.getEntity() == "Air");
}

bool GameState::valid(int _X, int _Y) {
	return (_X >= 0 && _Y >= 0 && _X < kolom && _Y < baris);
}

void GameState::regenerateWildEngimons() {
	// Mengatur pergerakan wild engimon
	if (round % MOVE_ROUND == 0) {
		moveWildEngimons();
	}

	// Mengatur spawn wild engimon baru
	if (round % SPAWN_ROUND == 0) {
		if (MAX_WILD > wildCount) {
			spawn(rand() % 2);
		}
	}
}

int GameState::searchIdEngimon(WildEngimon w) {
	int *listId;
	int j = 0;
	for (int i = 0; i < ENGIMON_COUNT; i++) {
		if (w.isSameType(listEngimons[i])) {
			listId[j] = listEngimons[i].getId();
			j++;
		}
	}
	if (j != 0) {
		return listId[rand() % j];
	}
}

int GameState::searchIdEngimon(char _symbol) {
	int *listId;
	listId = new int[ENGIMON_COUNT];
	int j = 0;
	for (int i = 0; i < ENGIMON_COUNT; i++) {
		if (tolower(listEngimons[i].getSymbol()) == tolower(_symbol)) {
			listId[j] = listEngimons[i].getId();
			j++;
		}
	}
	if (j != 0) {
		return listId[rand() % j];
	}
}
