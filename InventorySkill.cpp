#include <iostream>
#include <iterator>
#include <map>
#include "InventorySkill.hpp"
#include "Engimon.hpp"
#include "Skill.hpp"

using namespace std;

InventorySkill::InventorySkill() {
    map<Skill, int> skills;
    this->inventorySkill = skills;
}

InventorySkill::~InventorySkill() {}

int InventorySkill::numOfElement(){
    return this->inventorySkill.size();
}

void InventorySkill::initSkill(){
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

void InventorySkill::printInventorySkill() {
    map<Skill, int>::iterator itr;
    int menu = -1;
    string E, S;

    cout << "~~ Inventory ~~ " << endl;

    while (menu != 9) {
        cout << "Menu inventory : " << endl;
        cout << "1. Tampilkan engimon inventory" << endl;
        cout << "2. Tampilkan skills inventory" << endl;
        cout << "3. Engimon learn skill" << endl;

        cout << "9. Keluar" << endl;

        cout << "Masukkan nomor menu : ";
        cin >> menu ;

        if (menu == 2) {
            cout << "Skills : " << endl;
            for(auto elem : inventorySkill) {
                std::cout << elem.first.getNamaSkill() << " : " << elem.second << "pcs" << endl;
            }
        }
        else if (menu == 3) {
            cout << "Masukkan nama engimon : " ;
            cin >> E;
            cout << "Masukkan nama skill : " ;
            cin >> S;

            this->learn(E, S);
        }
    }

}

Skill InventorySkill::nameToSkill(string namaSkill){
	bool found = false;
	Skill skill;
	int i = 0;
	while(!found && i < 20 /*jml skill di katalog */){
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

void InventorySkill::learn(string E, string S) {
    // convert nama ke datatype skill
    Skill _S = this->nameToSkill(S);
    // convert nama ke datatype engimon
    Engimon _E ; 

    if (_E.getNumSkill() == 4) {
        char input = 'z';
        cout << "Engimon sudah mencapai jumlah skill maksimum" << endl;
        cout << "Apakah anda ingin mereplace salahsatu skill yg sudah dipelajari dgn skill baru ini? (y/n)" << endl;
        while (input != 'y' || input != 'n') {
            cin >> input;
            if (input == 'y') {
                this->replaceSkill(_E, _S);
            }
            else if (input != 'n') {
                cout << "input invalid, masukkan ulang input" << endl;
            }
        }
    }
    else {
        bool found = false;
        for (int i=0 ; i<_E.getNumElements(); i++) {
            if (_E.getElement(i) == _S.getSkillElements()) {
                found = true;
            }
        }
        if (!found) {
            cout << "Elemen engimon dan skill berbeda" << endl;
        }
        else {
            _E.addSkill(_S);
        }
    }
}

void InventorySkill::addItem(string s) {
    if ( 1/*inventorySkill.size() < capacity */) {
        Skill _S = this->nameToSkill(s);

        bool found = false;
        for(auto elem : inventorySkill) {
            if (elem.first.getNamaSkill() == s) {
                found = true;
            }
        }

        if (!found) {
            // skill blm ada di inventory
            inventorySkill.insert(pair<Skill, int>(_S, 1));
        }
        else {
            // skill sudah ada di inventory
            for(auto elem : inventorySkill ) {
                if (elem.first == _S) {
                    elem.second ++;
                }
            }
        }
    }
}
void InventorySkill::replaceSkill(Engimon E, Skill S) {
	string _skill;
	cout << "Mohon masukkan nama skill yang akan dihapus dengan benar" << endl;
	try {
		cin >> _skill;
		E.removeSkill(_skill);
		E.addSkill(S);
	} catch (Exception e) {
		e.displayMessage();
	}
}

void InventorySkill::useItem(string s) {
    for(auto elem : inventorySkill ) {
        if (elem.first.getNamaSkill() == s) {
            elem.second --;
            if (elem.second == 0) {
                inventorySkill.erase(elem.first);
            }
        }
    }
}
