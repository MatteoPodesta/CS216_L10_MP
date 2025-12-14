
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std;

#include "Game.h"

Game::Game(Army inputArmy1, Army inputArmy2) {

    Army Army1(inputArmy1);
    Army Army2(inputArmy2);

    //A is 0 and B is 1
    int turnAorB = rand() % 2;
    int currentTurn = 0;

    if (Army1.getSize() == Army2.getSize()) {   
        
        int size = inputArmy1.getSize();
        
        for (int i = 0; i < size; i++) {
            cout << "TURN " << i + 1 << endl
                << setfill('_') << left << setw(10) << "ATTACKER" << right << setw(10) << setfill('_') << "DAMAGE" << setw(10) << "TEAM"
                << " || "
                << left << setw(10) << "ATTACKER" << right << setw(10) << setfill('_') << "HEALTH" << setw(10) << "TEAM"
                << "\n\n";

            while (Army1.getList()[i]->getHealth() > 0 && Army2.getList()[i]->getHealth() > 0) {

                if (turnAorB == 0) {

                    turnAorB = 1;
                    doTurn(Army1, Army2, i);
                }
                else {

                    turnAorB = 0;
                    doTurn(Army2, Army1, i);
                }


            }

            if (Army1.getList()[i]->getHealth() == 0) {

                cout << endl << Army1.getList()[i]->getName() << " WON THE ROUND!\n"
                    << Army2.getList()[i]->getName() << " HAS 0 HEALTH SO THEY LOST THE ROUND...\n";

            }
            else {

                cout << endl << Army2.getList()[i]->getName() << " WON THE ROUND!\n"
                    << Army1.getList()[i]->getName() << " HAS 0 HEALTH SO THEY LOST THE ROUND...\n";

            }

            cout << "" << right << setw(65) << setfill('=') << "" << endl << endl;
        }

        if (calculateTeamScore(Army1, size) > calculateTeamScore(Army2, size)) {

            cout << "TEAM " << Army1.getName() << " WINS WITH " << calculateTeamScore(Army1, size) << " POINTS!\n"
                << "TEAM " << Army2.getName() << " LOST WITH " << calculateTeamScore(Army2, size) << " POINTS...\n";

        }
        else if (calculateTeamScore(Army1, size) == calculateTeamScore(Army2, size)) {

            cout << "BOTH TEAMS TIED WITH " << calculateTeamScore(Army1, size) << " POINTS!\n";

        }
        else {

            cout << "TEAM " << Army2.getName() << " WINS WITH " << calculateTeamScore(Army2, size) << " POINTS!\n"
                << "TEAM " << Army1.getName() << " LOST WITH " << calculateTeamScore(Army1, size) << " POINTS...\n";

        }

    }
    else {

        cout << "List Sizes are not Equal, please use equal list sizes." << endl;

    }

}
void Game::doTurn(Army& Attacker, Army& Defender, int index) {

    int Damage = Attacker.getCreature(index).getDamage();

    Defender.setCreatureHealth(index, Defender.getCreature(index).getHealth() - Damage);

    cout << setfill('_') << left << setw(10) << Attacker.getCreature(index).getCreatureFullName() << right << setw(10) << setfill('_') << Damage << setw(10) << Attacker.getName()
        << " || "
        << left << setw(10) << Defender.getCreature(index).getCreatureFullName() << right << setw(10) << setfill('_') << Defender.getCreature(index).getHealth() << setw(10) << Defender.getName()
        << "\n";

}
int Game::calculateTeamScore(Army array, int size) {

    int score = 0;

    for (int i = 0; i < size; i++) {

        score = score + array.getList()[i]->getHealth();

    }

    return score;
}
