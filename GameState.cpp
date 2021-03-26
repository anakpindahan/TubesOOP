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
	map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity(
			"Player");
	map[player.getCoordinate().getX()][player.getCoordinate().getY()].setSymbol(
			'P');

	srand(time(NULL));

	initSkill();

	// Menmbuat list engimon
	initEngimon();

	// Memberi player beberapa engimon acak
	for (int i = 0; i < START_ENGIMON; i++) {
		Engimon e;
		e = listEngimons[rand() % ENGIMON_COUNT];
		cout << "Kamu mendapatkan " << e.getSpecies() << "!" <<endl;
		cout << "Silahkan beri nama: ";
		string nama;
		cin >> nama;
		RealEngimon r(e.getId(), PLAYER_ENGIMON, e.getSpecies(),
				e.getSlogan(), e.getMaxExp(), Cell(),
				31 + (rand() % 10), rand() % 100, nama);
		for (int k = 0; k < e.getNumElements(); k++) {
			r.addElements(e.getElement(k));
		}
		r.setSymbol(e.getSymbol());
		r.setSymbolLevel();
		priority_queue<Skill> pq = e.getSkill();
		for (int k = 0; k < e.getNumSkill(); k++) {
			r.addSkill(pq.top());
			pq.pop();
		}
		player.addEngimon(r);
	}
	playerEngimon = 3;

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
	map[player.getCoordinate().getX()][player.getCoordinate().getY()].setEntity(
			"Player");
	map[player.getCoordinate().getX()][player.getCoordinate().getY()].setSymbol(
			'P');

	srand(time(NULL));

	for (int i = 0; i < START_ENGIMON; i++) {
			Engimon e;
			e = listEngimons[rand() % ENGIMON_COUNT];
			cout << "Kamu mendapatkan " << e.getSpecies() << "!" <<endl;
			cout << "Silahkan beri nama: ";
			string nama;
			cin >> nama;
			RealEngimon r(e.getId(), PLAYER_ENGIMON, e.getSpecies(),
					e.getSlogan(), e.getMaxExp(), Cell(),
					31 + (rand() % 10), rand() % 100, nama);
			for (int k = 0; k < e.getNumElements(); k++) {
				r.addElements(e.getElement(k));
			}
			r.setSymbol(e.getSymbol());
			r.setSymbolLevel();
			priority_queue<Skill> pq = e.getSkill();
			for (int k = 0; k < e.getNumSkill(); k++) {
				r.addSkill(pq.top());
				pq.pop();
			}
			player.addEngimon(r);
		}
	playerEngimon = 3;

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
	listEngimons[0] = Engimon(1, "Charmeleon", "Cha cha real smooth", 70000);
	listEngimons[0].addElements("Fire");
	listEngimons[0].addSkill(listSkills[0]);
	listEngimons[0].addSkill(listSkills[15]);

	listEngimons[1] = Engimon(2, "Omanyte", "Ooo man ooo man", 60000);
	listEngimons[1].addElements("Water");
	listEngimons[1].addSkill(listSkills[11]);
	listEngimons[1].addSkill(listSkills[17]);


	listEngimons[2] = Engimon(3, "Doraemon", "Aku ini kucing, bukan musang",
			66000);
	listEngimons[2].addElements("Ice");
	listEngimons[2].addSkill(listSkills[2]);
	listEngimons[2].addSkill(listSkills[4]);
	listEngimons[2].addSkill(listSkills[13]);

	listEngimons[3] = Engimon(4, "Pikachu", "Pika pika", 120000);
	listEngimons[3].addElements("Electric");
	listEngimons[3].addSkill(listSkills[3]);
	listEngimons[3].addSkill(listSkills[10]);
	listEngimons[3].addSkill(listSkills[15]);

	listEngimons[4] = Engimon(5, "BoboiBoyGempa", "Terbaek", 75000);
	listEngimons[4].addElements("Ground");
	listEngimons[4].addSkill(listSkills[4]);
	listEngimons[4].addSkill(listSkills[5]);

	listEngimons[5] = Engimon(6, "LaCorona",
			"Siapa itu yang minta libur setahun?", 55500);
	listEngimons[5].addElements("Water");
	listEngimons[5].addElements("Ice");
	listEngimons[5].addSkill(listSkills[4]);
	listEngimons[5].addSkill(listSkills[11]);
	listEngimons[5].addSkill(listSkills[14]);

	listEngimons[6] = Engimon(7, "Buzz", "Ah yes, the floor here made of floor",
			60000);
	listEngimons[6].addElements("Water");
	listEngimons[6].addElements("Ground");
	listEngimons[6].addSkill(listSkills[1]);
	listEngimons[6].addSkill(listSkills[11]);
	listEngimons[6].addSkill(listSkills[16]);
	listEngimons[6].addSkill(listSkills[17]);

	listEngimons[7] = Engimon(8, "Boot", "Boot boot boot", 80000);
	listEngimons[7].addElements("Fire");
	listEngimons[7].addElements("Electric");
	listEngimons[7].addSkill(listSkills[4]);
	listEngimons[7].addSkill(listSkills[15]);


	listEngimons[8] = Engimon(9, "AHHA", "Ashiaaaap", 55500);
	listEngimons[8].addElements("Electric");
	listEngimons[8].addSkill(listSkills[10]);
	listEngimons[8].addSkill(listSkills[12]);


	listEngimons[9] = Engimon(10, "DewiUseless", "Wheee, Kazumaaaa", 77800);
	listEngimons[9].addElements("Water");
	listEngimons[9].addElements("Ice");
	listEngimons[9].addSkill(listSkills[4]);
	listEngimons[9].addSkill(listSkills[7]);

	listEngimons[10] = Engimon(11, "YukiOnna", "Hurururururu", 88200);
	listEngimons[10].addElements("Ice");
	listEngimons[10].addSkill(listSkills[4]);
	listEngimons[10].addSkill(listSkills[8]);

	listEngimons[11] = Engimon(12, "Oopsie", "Ctor cctor dtor", 65000);
	listEngimons[11].addElements("Ground");
	listEngimons[11].addSkill(listSkills[13]);
	listEngimons[11].addSkill(listSkills[16]);


}

void GameState::initSkill(){
	listSkills[0] = Skill("FireBall", 200, 1);
	listSkills[0].addSkillElements("Fire");
	
	listSkills[1] = Skill("WaterCannon", 190, 1);
	listSkills[1].addSkillElements("Water");
	
	listSkills[2] = Skill("SnowBall", 250, 1);
	listSkills[2].addSkillElements("Ice");
	
	listSkills[3] = Skill("Kirin", 300, 1);
	listSkills[3].addSkillElements("Electric");
	
	listSkills[4] = Skill("Tampar", 100, 1);
	listSkills[4].addSkillElements("Fire");
	listSkills[4].addSkillElements("Ground");
	listSkills[4].addSkillElements("Water");
	listSkills[4].addSkillElements("Electric");
	listSkills[4].addSkillElements("Ice");
	
	listSkills[12] = Skill("Jitak", 120, 1);
	listSkills[12].addSkillElements("Fire");
	listSkills[12].addSkillElements("Ground");
	listSkills[12].addSkillElements("Water");
	listSkills[12].addSkillElements("Electric");
	listSkills[12].addSkillElements("Ice");
	
	listSkills[13] = Skill("Terbang", 120, 1);
	listSkills[13].addSkillElements("Fire");
	listSkills[13].addSkillElements("Water");
	listSkills[13].addSkillElements("Electric");
	listSkills[13].addSkillElements("Ground");
	
	listSkills[5] = Skill("TanahTinggi", 220, 1);
	listSkills[5].addSkillElements("Ground");
	
	listSkills[6] = Skill("ApiAmarah", 300, 1);
	listSkills[6].addSkillElements("Fire");
	
	listSkills[7] = Skill("SusuMilo", 240, 1);
	listSkills[7].addSkillElements("Water");
	listSkills[7].addSkillElements("Ice");
	
	listSkills[8] = Skill("EsKepal", 300, 1);
	listSkills[8].addSkillElements("Ice");
	
	listSkills[9] = Skill("FireDance", 150, 1);
	listSkills[9].addSkillElements("Fire");
	
	listSkills[10] = Skill("LightningStrike", 280, 1);
	listSkills[10].addSkillElements("Electric");
	
	listSkills[11] = Skill("Blizzaro", 300, 1);
	listSkills[11].addSkillElements("Water");
	listSkills[11].addSkillElements("Ground");
	
	listSkills[14] = Skill("Pandemonium", 250, 1);
	listSkills[14].addSkillElements("Ground");
	listSkills[14].addSkillElements("Ice");
	
	listSkills[15] = Skill("DomainExpansion", 320, 1);
	listSkills[15].addSkillElements("Fire");
	listSkills[15].addSkillElements("Electric");
	
	listSkills[16] = Skill("Wadimorphism", 320, 1);
	listSkills[16].addSkillElements("Ground");
	
	listSkills[17] = Skill("WaterSplash", 90, 1);
	listSkills[17].addSkillElements("Water");
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
	cout << "1. Move (melakukan pergerakan)" << endl;
	cout << "2. Breed (mengawinkan engimon)" << endl;
	cout << "3. Stat (melihat data dari engimon yang dipunyai)" << endl;
	cout << "4. Switch (mengganti active engimon)" << endl;
	cout << "5. ShowSkillItem (melihat skill item yang ada)" << endl;
	cout << "6. UseSkillItem (menggunakan skill item yang ada)" << endl;
	cout << "7. Battle (bertarung dengan wild engimon yang ada)" << endl;
	cout << "8. Exit (untuk keluar dari permainan)" << endl;
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
		breedPlayerEngimons();
	} else if(_command == "Stat"){
		for(int i = 1; i <= playerEngimon; i++){
			player.getInventoryEngimon().getEngimon(i).showStat();
			cout << endl;
		}
	} else if(_command == "Battle"){
		battlePlayerEngimon();
	} else if(_command == "ShowSkillItem"){
		player.getInventorySkill().printInventorySkill();
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

			Engimon e = listEngimons[idE - 1];
			wildEngimons[i] = RealEngimon(e.getId(), WILD_ENGIMON, e.getSpecies(),
					e.getSlogan(), e.getMaxExp(), Cell(), 30 + (rand() % 10),
					rand() % 100, "No Name");
			for(int k = 0; k < e.getNumElements(); k++){
				wildEngimons[i].addElements(e.getElement(k));
			}
			wildEngimons[i].setSymbol(e.getSymbol());
			wildEngimons[i].setSymbolLevel();
			wildEngimons[i].setCoordinate(x, y);
			priority_queue<Skill> pq = e.getSkill();
			for(int k = 0; k < e.getNumSkill(); k++){
				wildEngimons[i].addSkill(pq.top());
				pq.pop();
			}
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

void GameState::breedPlayerEngimons() {

	int e1, e2;
	cout << "Masukkan dua nomor engimon yang ingin dikawinkan" << endl;
	cin >> e1 >> e2;
	try {
		RealEngimon child = player.getInventoryEngimon().getEngimon(e1).breed(player.getInventoryEngimon().getEngimon(e2));
		child.setStatus(PLAYER_ENGIMON);
		int i = searchIdEngimon(child) - 1;
		cout << i << endl;
		if(child.getId() <= 0){
			child.setId(i);
			child.setSpecies(listEngimons[i].getSpecies());
			child.setMaxExp(listEngimons[i].getMaxExp());
			child.setSlogan(listEngimons[i].getSlogan());
			child.setSymbol(listEngimons[i].getSymbol());
		}
		cout << "Anda mendapatkan bayi " << child.getSpecies() << endl;
		cout << "Masukkan nama bayi engimon: ";
		string _name;
		cin >> _name;
		child.setName(_name);
		playerEngimon++;
		player.addEngimon(child);

		cout << "Sambutlah bayi engimon barumu: " << endl;
		child.showStat();

		round++;
		regenerateWildEngimons();
	} catch (Exception e) {
		e.displayMessage();
	}
}

void GameState::battlePlayerEngimon() {
	Battle B;
	string direction;
	int noEngimon;
	cout << "Silahkan pilih arah engimon liar yang akan dilawan: (A, W, S, D)"
			<< endl;
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
		throw(Exception(WRONG_COMMAND));
	}
	this->player.getInventoryEngimon().showNameEngimonContents();
	cout << "Silahkan pilih nomor engimon yang ingin digunakan" << endl;
	cin >> noEngimon;

	try {
		RealEngimon B1 = player.getInventoryEngimon().getEngimon(noEngimon);
		RealEngimon B2 = wildEngimons[searchIdWildEngimon(Cell(k,l,"","",'X'))];
		B.elementAdv1(B1, B2);
		B.tanding(this->player,noEngimon, wildEngimons[searchIdWildEngimon(Cell(k, l, "", "", 'X'))], (B1).getSkill().top(), (B2).getSkill().top());
	} catch (Exception e) {
		e.displayMessage();
	}
}

int GameState::searchIdEngimon(RealEngimon w) {
	int *listId;
	listId = new int[ENGIMON_COUNT];
	int j = 0;
	for (int i = 0; i < ENGIMON_COUNT; i++) {
		if (listEngimons[i].isSameType(w)) {
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

int GameState::searchIdWildEngimon(Cell cell) {
	bool found = false;
	int i = 0;
	while(i < MAX_WILD && !found){
		if (wildEngimons[i].getCoordinate() == cell) {
			found = true;
		}
		else{
			i++;
		}
	}
	if (found) {
		return i;
	} else {
		throw(Exception(NO_WILD_ENGIMON));
	}
}

Skill GameState::generateSkill(Engimon engimon){
	int found = false;
	Skill skill;
	int index = rand() % engimon.getNumSkill();
	for (int i = 0; i < index+1; i++){
		engimon.getSkill().pop();
	}
	skill.operator=(engimon.getSkill().top());
	return skill;
}

Skill GameState::searchSkill(string namaSkill){
	bool found = false;
	Skill skill;
	int i = 0;
	while(!found && i < SKILL_COUNT){
		if(this->listSkills[i].getNamaSkill() == namaSkill){
			found =true;
		}else{
			i++;
		}
	}
	if(found){
		return this->listSkills[i];
	}else{
		return skill;
	}
}
