#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std;

#include "Army.h"

Army::Army(int newSize, string newName) {

    name = newName;
    size = newSize;
    int creature = 0;
    int health = 0;
    int strength = 0;
    int index = 0;
    pCreature = new Creature * [size] {nullptr};

    try {

        for (int i = 0; i < size; ++i) {

            creature = rand() % 3;
            health = 30 + (rand() % (90 - 30 + 1));
            strength = 30 + (rand() % (90 - 30 + 1));

            switch (creature) {
            case 0:

                pCreature[i] = new Elf("Creature" + to_string(i + 1), health, strength);
                break;

            case 1:

                pCreature[i] = new Demon("Creature" + to_string(i + 1), health, strength);
                break;

            case 2:

                pCreature[i] = new Superdemon("Creature" + to_string(i + 1), health, strength);
                break;

            default:

                pCreature[i] = nullptr;
                break;

            }
        }

        index++;

    }
    catch (bad_alloc) {

        cout << "BAD ALLOC ERROR: NEW ATTEMPT FAILED AT " << index << endl;
        deAllocateMemory(pCreature, size);

    }
    catch (...) {

        cout << "UNKNOWN ERROR!\n";
        deAllocateMemory(pCreature, size);

    }
};
Army::Army(const Army& copyFromThisArmy) {

    size = copyFromThisArmy.size;
    name = copyFromThisArmy.name;
    pCreature = copyFromThisArmy.pCreature;

    pCreature = new Creature * [size] {nullptr};

    for (int i = 0; i < size; i++) {

        pCreature[i] = copyFromThisArmy.pCreature[i];

    }

}
Army& Army::operator=(const Army& rightArmy) {

    if (this != &rightArmy) {

        this->name = rightArmy.name;
        this->size = rightArmy.size;

        for (int i = 0; i < size; i++) {

            this->pCreature[i] = rightArmy.pCreature[i];

        }

    }

    return *this;
}

void Army::printList() {

    cout << left << setw(14)
        << "Name" << setw(10)
        << "Health" << setw(16)
        << "Strength" << setw(15)
        << "Type" << setw(1) << setfill('_') << "\n"
        << "" << right << setw(55) << setfill('=') << "" << endl;

    for (int i = 0; i < size; ++i) {

        cout << pCreature[i]->toString() << endl;

    }

    cout << "" << right << setw(55) << setfill('=') << "" << endl;

}
void Army::setCreatureHealth(int index, int newHealth) {
    if (newHealth < 0) {

        newHealth = 0;

    }

    setCreature(index, pCreature[index]->getName(), newHealth, pCreature[index]->getStrength());

}
void Army::deAllocateMemory(Creature**& array, int size) {

    if (array != nullptr)
    {
        for (int i = 0; i < size; ++i) {

            delete array[i];
            array[i] = nullptr;

        }
        delete[] array;
        array = nullptr;
    }



}