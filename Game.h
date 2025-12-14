#ifndef GAME
#define GAME

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std;

#include "Army.h"

class Game {
public:

    Game(Army inputArmy1, Army inputArmy2);

    void doTurn(Army& Attacker, Army& Defender, int index);
    int calculateTeamScore(Army array, int size);

};

#endif // !GAME