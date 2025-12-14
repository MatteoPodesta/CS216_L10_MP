#ifndef CREATURE
#define CREATURE

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std;

const string DEFAULT_NAME = "nameHere";
const int DEFAULT_HEALTH = 50;
const int DEFAULT_STRENGTH = 50;
const string DEFAULT_TYPE = "Creature";

class CreatureExeption {

public:
    CreatureExeption() {
        message = "UNKNOWN ERROR";
    }
    CreatureExeption(int value) {
        message = value;
    }
    CreatureExeption(string value) {
        message = value;
    }
    string what() {
        return message;
    }
private:

    string message = "";

};

class Creature {
public:

    Creature() {

        setCreature(DEFAULT_NAME, DEFAULT_HEALTH, DEFAULT_STRENGTH);

    }
    Creature(string name) {

        setCreature(name, health, strength);

    }
    Creature(int health, int strength) {

        setCreature(name, health, strength);

    }
    Creature(string name, int health, int strength) {

        setCreature(name, health, strength);

    }
    Creature(const Creature& copyFromThisCreature) {

        setCreature(copyFromThisCreature.name, copyFromThisCreature.health, copyFromThisCreature.strength);

    }
    Creature& operator=(const Creature& rightCreature);
    virtual ~Creature() {

        setCreature(DEFAULT_NAME, DEFAULT_HEALTH, DEFAULT_STRENGTH);

    }

    const string getName() {

        return name;

    }
    const int getHealth() {

        return health;

    }
    const int getStrength() {

        return strength;

    }
    int getDamage() {

        return (rand() % strength) + 1;

    }

    virtual const string getCreatureFullName() = 0;

    void setCreature(string newName, int newHealth, int newStrength);
    virtual string toString();

private:

    string name = DEFAULT_NAME;
    int health = DEFAULT_HEALTH;
    int strength = DEFAULT_STRENGTH;

};

class Elf : public Creature {
public:

    Elf() : Creature() { }
    Elf(string newName) : Creature(newName) { }
    Elf(int newHealth, int newStrength) : Creature(newHealth, newStrength) { }
    Elf(string newName, int newHealth, int newStrength) : Creature(newName, newHealth, newStrength) { }
    Elf(Creature& copyFromThisCreature) : Creature(copyFromThisCreature) { }
    ~Elf() {

        Creature::~Creature();

    }

    const string getCreatureFullName() override;

    string toString();
    int getDamage() {

        return (rand() % 20) == 0 ? getDamage() * 2 : getDamage();

    }

};

class Demon : public Creature {
public:

    Demon() : Creature() { }
    Demon(string newName) : Creature(newName) { }
    Demon(int newHealth, int newStrength) : Creature(newHealth, newStrength) { }
    Demon(string newName, int newHealth, int newStrength) : Creature(newName, newHealth, newStrength) { }
    Demon(Creature& copyFromThisCreature) : Creature(copyFromThisCreature) { }
    ~Demon() {

        Creature::~Creature();

    }

    const string getCreatureFullName() override;

    string toString();
    int getDamage() {

        return (rand() % 100) < 15 ? getDamage() + 50 : getDamage();

    }

};

class Superdemon : public Demon {
public:

    Superdemon() : Demon() { }
    Superdemon(string newName) : Demon(newName) { }
    Superdemon(int newHealth, int newStrength) : Demon(newHealth, newStrength) { }
    Superdemon(string newName, int newHealth, int newStrength) : Demon(newName, newHealth, newStrength) { }
    Superdemon(Creature& copyFromThisCreature) : Demon(copyFromThisCreature) { }
    ~Superdemon() {

        Creature::~Creature();

    }

    const string getCreatureFullName() override;

    string toString();
    int getDamage() {

        return  Demon::getDamage() + Demon::getDamage();

    }

};

#endif // !CREATURE