#include "InventoryEngimon.hpp"

template <class T>
InventoryEngimon<T>::InventoryEngimon(){
    this->quantity = 0 ;
}

InventoryEngimon<T>::~InventoryEngimon(){}

int InventoryEngimon<T>::numOfElement(){
    return this->listEngimon.size();
}

void InventoryEngimon<T>::putIn(T engimon){
    this->listEngimon.push_back(engimon);
}

void InventoryEngimon<T>::truncate(){
    this->listEngimon.clear();
}

void InventoryEngimon<T>::deleteEngimon(int offset){
    this->listEngimon.erase(offset-1);
}

Engimon InventoryEngimon<T>::changeEngimon(T engimonInput, int offsetTarget){
    Engimon *temp = new Engimon();
    (*temp).operator=(this->listEngimon.at(offsetTarget-1));
    this->deleteEngimon(offsetTarget);
    this->putIn(engimonInput);
    return (*temp);    
}
    