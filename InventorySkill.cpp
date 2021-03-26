#include <iostream>
#include <iterator>
#include <map>
#include "InventorySkill.hpp"
#include "Engimon.hpp"
#include "Skill.hpp"

using namespace std;

InventorySkill::InventorySkill() {}

/*InventorySkill& InventorySkill::operator=(const InventorySkill& other) {
    InventorySkill x = new InventorySkill();
    x->inventorySkill = other.inventorySkill;
    return x;
}*/ //kayaknya gausah aja soalnya eror terus

InventorySkill::~InventorySkill() {}

int InventorySkill::numOfElement(){
    return this->inventorySkill.size();
}

void InventorySkill::printInventorySkill() {
    map<Skill, int>::iterator itr;
    int menu = -1;
    string E, S;

    cout << "~~ Inventory ~~ " << endl;

    while (menu != 0) {
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

Skill InventorySkill::nameToSkill(string s) {
    for(auto elem : inventorySkill) {
        if (elem.first.getNamaSkill() == s) {
            return elem.first;
        }
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
    // E.removeSkill() lagi request ke akeyla
    E.addSkill(S);
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
