#ifndef ARMY
#define ARMY

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std;

#include "Creature.h"

class Army {
public:

    Army() {

        pCreature = { nullptr };

    }
    Army(int newSize, string newName);
    Army(int newSize) : Army(newSize, name) { }
    Army(const Army& copyFromThisArmy);
    Army& operator=(const Army& rightArmy);
    ~Army() {

    }

    void setCreature(int index, string newName, int newHealth, int newStrength) {

        pCreature[index]->setCreature(newName, newHealth, newStrength);

    }
    void setCreatureHealth(int index, int newHealth);

    const int getSize() {

        return size;

    }
    const string getName() {

        return name;

    }

    Creature& getCreature(int index) {

        return *pCreature[index];

    }

    void printList();
    Creature** getList() {

        return pCreature;

    }
    void deAllocateMemory(Creature**& array, int size);

private:

    Creature** pCreature = nullptr;
    int size = 0;
    string name = DEFAULT_NAME;

};



#endif // !ARMY