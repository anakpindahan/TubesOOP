#include "InventoryEngimon.hpp"

template <class T>
InventoryEngimon<T>::InventoryEngimon(){
    // this->quantity = 0 ;
}
template <class T>
InventoryEngimon<T>::~InventoryEngimon(){}

template <class T>
int InventoryEngimon<T>::numOfElement(){
    return this->listEngimon.size();
}

template <class T>
void InventoryEngimon<T>::putIn(T& engimon){
    this->listEngimon.push_back(engimon);
}

template <class T>
void InventoryEngimon<T>::truncate(){
    this->listEngimon.clear();
}

template <class T>
void InventoryEngimon<T>::deleteEngimon(int offset){
    this->listEngimon.erase(this->listEngimon.begin()+offset-1);
}

template <class T>
T InventoryEngimon<T>::changeEngimon(T engimonInput, int offsetTarget){
    RealEngimon *temp = new RealEngimon();
    (*temp).operator=(this->listEngimon.at(offsetTarget-1));
    this->deleteEngimon(offsetTarget);
    this->putIn(engimonInput);
    return (*temp);    
}

template <class T>
T InventoryEngimon<T>::getEngimon(int i){
	return this->listEngimon.at(i - 1);
}

template class InventoryEngimon<RealEngimon>;
