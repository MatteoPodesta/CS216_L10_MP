#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std;

#include "Creature.h"

void Creature::setCreature(string newName, int newHealth, int newStrength) {

    int index = 0;
    int nameSize = 0;
    try {

        while (newName[index] != '@' && index < newName.size()) {

            if ((newName[index] >= '0' && newName[index] <= '9') || (newName[index] >= 'A' && newName[index] <= 'Z') || (newName[index] >= 'a' && newName[index] <= 'z')) {

                nameSize++;
            }
            index++;
        }

        if (nameSize < 3) {

            throw CreatureExeption(newName);

        }

        if (newHealth < 0) {

            throw CreatureExeption(newHealth);

        }

        if (newStrength < 0) {

            throw CreatureExeption(newStrength);

        }

        name = newName;
        health = newHealth;
        strength = newStrength;

    }
    catch (CreatureExeption ex) {

        cout << ex.what() << endl;

    }
    catch (...) {

        cout << "UNKNOWN ERROR..." << endl;

    }

};
Creature& Creature::operator=(const Creature& rightCreature) {

    if (this != &rightCreature) {

        this->setCreature(rightCreature.name, rightCreature.health, rightCreature.strength);

    }

    return *this;
}

string Creature::toString() {

    stringstream ss;
    ss << left << setw(10) << name << right << setw(10) << setfill('_') << health << setw(12) << strength;
    return ss.str();

}


string Elf::toString() {

    stringstream ss;
    ss << left << setw(40) << setfill('_') << Creature::toString() << setw(15) << setfill('_') << "Elf";
    return ss.str();

}
const string Elf::getCreatureFullName() {

    stringstream ss;
    ss << getName() << " the Elf";
    return ss.str();

}

string Demon::toString() {

    stringstream ss;
    ss << left << setw(40) << setfill('_') << Creature::toString() << setw(15) << setfill('_') << "Demon";
    return ss.str();

}
const string Demon::getCreatureFullName() {

    stringstream ss;
    ss << getName() << " the Demon";
    return ss.str();

}

string Superdemon::toString() {

    stringstream ss;
    ss << left << setw(40) << setfill('_') << Creature::toString() << setw(15) << setfill('_') << "Superdemon";
    return ss.str();

}
const string Superdemon::getCreatureFullName() {

    stringstream ss;
    ss << getName() << " the Superdemon";
    return ss.str();

}