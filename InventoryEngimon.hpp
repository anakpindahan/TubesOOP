#ifndef INVENTORY_ENGIMON
#define INVENTORY_ENGIMON

#include "Engimon.hpp"
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

template <class T>
class InventoryEngimon{
private:
    vector<T> listEngimon;
public:
    InventoryEngimon();
    ~InventoryEngimon();
    int numOfElement();
    void putIn(T);
    void truncate();
    void deleteEngimon(int);
    T changeEngimon(T engimonInput, int offsetTarget);
};

#endif

