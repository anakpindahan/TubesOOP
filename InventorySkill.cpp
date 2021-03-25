#include <iostream>
#include <iterator>
#include <map>
#include "InventorySkill.hpp"
#include "Engimon.hpp"

using namespace std;

Inventory::Inventory() {
    this->capacity = 30;
}
Inventory::Inventory(int c) {
    this->capacity = c;
}
Inventory& Inventory::operator=(const Inventory& other) {
    this->capacity = other.capacity;
    this->inventorySkill = other.inventorySkill;
}
Inventory::~Inventory() {
    
}
int Inventory::getMaxCapacity() {
    return this->capacity;
}
void Inventory::setMaxCapacity(int c) {
    this->capacity = c;
}
void Inventory::printInventory() {
    map<Skill, int>::iterator itr;
    int menu = -1;
    string E, S;

    cout << "~~ Inventory ~~ " << endl;
    cout << "Kapasitas maksimum : " << this->capacity << endl;

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

Skill Inventory::nameToSkill(string s) {
    for(auto elem : inventorySkill ) {
        if (elem.first.getNamaSkill() == s) {
            return elem.first;
        }
    }
}

void Inventory::learn(string E, string S) {
    // convert nama ke datatype skill
    Skill _S = this->nameToSkill(S);
    // convert nama ke datatype engimon
    Engimon _E ; 

    if (_E.getNumSkill() == 4) {
        cout << "Engimon sudah mencapai jumlah skill maksimum" << endl;
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
void Inventory::addItem(string s) {
    if (inventorySkill.size() < capacity) {
        Skill _S = this->nameToSkill(s);

        if (inventorySkill.find(_S) == inventorySkill.end()) {
            inventorySkill.insert(pair<Skill, int>(_S, 1));
        }
        else {
            for(auto elem : inventorySkill ) {
                if (elem.first == _S) {
                    elem.second ++;
                }
            }
        }
    }
}
void Inventory::replaceItem() {
    
}
void Inventory::useItem(string s) {
    for(auto elem : inventorySkill ) {
        if (elem.first.getNamaSkill() == s) {
            elem.second --;
            if (elem.second == 0) {
                inventorySkill.erase(elem.first);
            }
        }
    }
}