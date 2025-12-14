#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream> 
using namespace std;

#include "Creature.h"
#include "Army.h"
#include "Game.h"


void defaultMenuOption();
void deAllocateMemory(Creature**& array, int size);
void listfunction();
void armyFunction(int size);

int main()
{
    int size = 0;

    cout << "\n\nMenu:\n"
        << "Input Army Size: ";
    cin >> size;

    armyFunction(size);

    return 0;
}

void defaultMenuOption() {

    cout << "Invalid choice, try again\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

}
void listfunction() {

    int sizeInput;

    cout << "Input list size: ";
    cin >> sizeInput;

    Army creatureArmy(sizeInput);
    creatureArmy.printList();

}
void deAllocateMemory(Creature**& array, int size) {

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

void armyFunction(int size) {

    Army army1(size, "CHEESE");
    Army army2(size, "MAYO");

    int userInput = 0;
    enum {

        PRINT = 1,
        PLAY,
        QUIT

    };

    while (userInput != QUIT) {

        cout << "\n\nMenu:\n"
            << "1. Print Armies\n"
            << "2. Play Battle Game\n"
            << "3. Exit\n"
            << "\nInput: ";

        cin >> userInput;

        switch (userInput) {
        case PRINT:
            army1.printList();
            army2.printList();
            break;
        case PLAY:
        {
            Game game(army1, army2);
        }
        break;
        case QUIT:
            break;
        default:
            defaultMenuOption();
            break;
        }
    }


}

/*
TEST RUN -----



Menu:
Input Army Size: 25


Menu:
1. Print Armies
2. Play Battle Game
3. Exit

Input: 1
Name          Health    Strength        Type
=======================================================
Creature1 ________75__________81________Superdemon_____
Creature2 ________45__________77________Demon__________
Creature3 ________47__________30________Elf____________
Creature4 ________62__________54________Superdemon_____
Creature5 ________82__________48________Demon__________
Creature6 ________36__________77________Superdemon_____
Creature7 ________37__________30________Elf____________
Creature8 ________89__________61________Elf____________
Creature9 ________90__________66________Demon__________
Creature10________45__________39________Superdemon_____
Creature11________40__________39________Superdemon_____
Creature12________69__________56________Elf____________
Creature13________38__________46________Superdemon_____
Creature14________63__________51________Elf____________
Creature15________46__________74________Superdemon_____
Creature16________43__________55________Superdemon_____
Creature17________66__________79________Superdemon_____
Creature18________57__________30________Superdemon_____
Creature19________79__________30________Elf____________
Creature20________48__________76________Elf____________
Creature21________76__________77________Demon__________
Creature22________74__________63________Elf____________
Creature23________66__________79________Demon__________
Creature24________87__________45________Demon__________
Creature25________49__________61________Superdemon_____
=======================================================
Name==========Health====Strength========Type===========
=======================================================
Creature1 ________30__________82________Superdemon_____
Creature2 ________40__________78________Elf____________
Creature3 ________80__________37________Superdemon_____
Creature4 ________36__________55________Elf____________
Creature5 ________53__________47________Superdemon_____
Creature6 ________78__________73________Elf____________
Creature7 ________77__________35________Demon__________
Creature8 ________38__________84________Superdemon_____
Creature9 ________44__________35________Superdemon_____
Creature10________42__________42________Demon__________
Creature11________38__________79________Elf____________
Creature12________90__________49________Superdemon_____
Creature13________53__________70________Superdemon_____
Creature14________64__________89________Elf____________
Creature15________64__________72________Elf____________
Creature16________83__________41________Demon__________
Creature17________59__________31________Elf____________
Creature18________49__________35________Elf____________
Creature19________52__________82________Demon__________
Creature20________38__________88________Elf____________
Creature21________88__________87________Demon__________
Creature22________82__________54________Demon__________
Creature23________89__________43________Superdemon_____
Creature24________33__________31________Superdemon_____
Creature25________34__________74________Superdemon_____
=======================================================


Menu:
1. Print Armies
2. Play Battle Game
3. Exit

Input: 2
TURN 1
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature1 the Superdemon________80____CHEESE || Creature1 the Superdemon_________0______MAYO

Creature1 WON THE ROUND!
Creature1 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 2
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature2 the Elf________51______MAYO || Creature2 the Demon_________0____CHEESE

Creature2 WON THE ROUND!
Creature2 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 3
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature3 the Elf________11____CHEESE || Creature3 the Superdemon________69______MAYO
Creature3 the Superdemon________23______MAYO || Creature3 the Elf________24____CHEESE
Creature3 the Elf_________9____CHEESE || Creature3 the Superdemon________60______MAYO
Creature3 the Superdemon________13______MAYO || Creature3 the Elf________11____CHEESE
Creature3 the Elf________12____CHEESE || Creature3 the Superdemon________48______MAYO
Creature3 the Superdemon_________4______MAYO || Creature3 the Elf_________7____CHEESE
Creature3 the Elf_________6____CHEESE || Creature3 the Superdemon________42______MAYO
Creature3 the Superdemon________21______MAYO || Creature3 the Elf_________0____CHEESE

Creature3 WON THE ROUND!
Creature3 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 4
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature4 the Superdemon________42____CHEESE || Creature4 the Elf_________0______MAYO

Creature4 WON THE ROUND!
Creature4 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 5
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature5 the Superdemon________36______MAYO || Creature5 the Demon________46____CHEESE
Creature5 the Demon________42____CHEESE || Creature5 the Superdemon________11______MAYO
Creature5 the Superdemon________23______MAYO || Creature5 the Demon________23____CHEESE
Creature5 the Demon_________4____CHEESE || Creature5 the Superdemon_________7______MAYO
Creature5 the Superdemon_________7______MAYO || Creature5 the Demon________16____CHEESE
Creature5 the Demon________10____CHEESE || Creature5 the Superdemon_________0______MAYO

Creature5 WON THE ROUND!
Creature5 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 6
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature6 the Elf________26______MAYO || Creature6 the Superdemon________10____CHEESE
Creature6 the Superdemon________19____CHEESE || Creature6 the Elf________59______MAYO
Creature6 the Elf________72______MAYO || Creature6 the Superdemon_________0____CHEESE

Creature6 WON THE ROUND!
Creature6 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 7
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature7 the Elf________27____CHEESE || Creature7 the Demon________50______MAYO
Creature7 the Demon________30______MAYO || Creature7 the Elf_________7____CHEESE
Creature7 the Elf________11____CHEESE || Creature7 the Demon________39______MAYO
Creature7 the Demon________12______MAYO || Creature7 the Elf_________0____CHEESE

Creature7 WON THE ROUND!
Creature7 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 8
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature8 the Elf________49____CHEESE || Creature8 the Superdemon_________0______MAYO

Creature8 WON THE ROUND!
Creature8 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 9
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature9 the Superdemon________14______MAYO || Creature9 the Demon________76____CHEESE
Creature9 the Demon________34____CHEESE || Creature9 the Superdemon________10______MAYO
Creature9 the Superdemon________34______MAYO || Creature9 the Demon________42____CHEESE
Creature9 the Demon________65____CHEESE || Creature9 the Superdemon_________0______MAYO

Creature9 WON THE ROUND!
Creature9 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 10
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature10 the Demon_________8______MAYO || Creature10 the Superdemon________37____CHEESE
Creature10 the Superdemon________16____CHEESE || Creature10 the Demon________26______MAYO
Creature10 the Demon________12______MAYO || Creature10 the Superdemon________25____CHEESE
Creature10 the Superdemon________11____CHEESE || Creature10 the Demon________15______MAYO
Creature10 the Demon_________1______MAYO || Creature10 the Superdemon________24____CHEESE
Creature10 the Superdemon________15____CHEESE || Creature10 the Demon_________0______MAYO

Creature10 WON THE ROUND!
Creature10 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 11
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature11 the Elf________28______MAYO || Creature11 the Superdemon________12____CHEESE
Creature11 the Superdemon_________6____CHEESE || Creature11 the Elf________32______MAYO
Creature11 the Elf________37______MAYO || Creature11 the Superdemon_________0____CHEESE

Creature11 WON THE ROUND!
Creature11 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 12
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature12 the Elf________20____CHEESE || Creature12 the Superdemon________70______MAYO
Creature12 the Superdemon_________5______MAYO || Creature12 the Elf________64____CHEESE
Creature12 the Elf________54____CHEESE || Creature12 the Superdemon________16______MAYO
Creature12 the Superdemon_________2______MAYO || Creature12 the Elf________62____CHEESE
Creature12 the Elf________28____CHEESE || Creature12 the Superdemon_________0______MAYO

Creature12 WON THE ROUND!
Creature12 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 13
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature13 the Superdemon________28______MAYO || Creature13 the Superdemon________10____CHEESE
Creature13 the Superdemon________30____CHEESE || Creature13 the Superdemon________23______MAYO
Creature13 the Superdemon________31______MAYO || Creature13 the Superdemon_________0____CHEESE

Creature13 WON THE ROUND!
Creature13 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 14
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature14 the Elf________39____CHEESE || Creature14 the Elf________25______MAYO
Creature14 the Elf________30______MAYO || Creature14 the Elf________33____CHEESE
Creature14 the Elf________29____CHEESE || Creature14 the Elf_________0______MAYO

Creature14 WON THE ROUND!
Creature14 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 15
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature15 the Elf________54______MAYO || Creature15 the Superdemon_________0____CHEESE

Creature15 WON THE ROUND!
Creature15 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 16
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature16 the Superdemon________27____CHEESE || Creature16 the Demon________56______MAYO
Creature16 the Demon________35______MAYO || Creature16 the Superdemon_________8____CHEESE
Creature16 the Superdemon________17____CHEESE || Creature16 the Demon________39______MAYO
Creature16 the Demon________19______MAYO || Creature16 the Superdemon_________0____CHEESE

Creature16 WON THE ROUND!
Creature16 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 17
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature17 the Superdemon________36____CHEESE || Creature17 the Elf________23______MAYO
Creature17 the Elf________28______MAYO || Creature17 the Superdemon________38____CHEESE
Creature17 the Superdemon________36____CHEESE || Creature17 the Elf_________0______MAYO

Creature17 WON THE ROUND!
Creature17 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 18
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature18 the Elf________14______MAYO || Creature18 the Superdemon________43____CHEESE
Creature18 the Superdemon_________4____CHEESE || Creature18 the Elf________45______MAYO
Creature18 the Elf________30______MAYO || Creature18 the Superdemon________13____CHEESE
Creature18 the Superdemon________29____CHEESE || Creature18 the Elf________16______MAYO
Creature18 the Elf________35______MAYO || Creature18 the Superdemon_________0____CHEESE

Creature18 WON THE ROUND!
Creature18 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 19
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature19 the Elf________30____CHEESE || Creature19 the Demon________22______MAYO
Creature19 the Demon________66______MAYO || Creature19 the Elf________13____CHEESE
Creature19 the Elf_________3____CHEESE || Creature19 the Demon________19______MAYO
Creature19 the Demon________80______MAYO || Creature19 the Elf_________0____CHEESE

Creature19 WON THE ROUND!
Creature19 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 20
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature20 the Elf________42____CHEESE || Creature20 the Elf_________0______MAYO

Creature20 WON THE ROUND!
Creature20 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 21
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature21 the Demon________49______MAYO || Creature21 the Demon________27____CHEESE
Creature21 the Demon________22____CHEESE || Creature21 the Demon________66______MAYO
Creature21 the Demon________74______MAYO || Creature21 the Demon_________0____CHEESE

Creature21 WON THE ROUND!
Creature21 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 22
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature22 the Elf________13____CHEESE || Creature22 the Demon________69______MAYO
Creature22 the Demon________47______MAYO || Creature22 the Elf________27____CHEESE
Creature22 the Elf________54____CHEESE || Creature22 the Demon________15______MAYO
Creature22 the Demon________51______MAYO || Creature22 the Elf_________0____CHEESE

Creature22 WON THE ROUND!
Creature22 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 23
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature23 the Demon________79____CHEESE || Creature23 the Superdemon________10______MAYO
Creature23 the Superdemon________43______MAYO || Creature23 the Demon________23____CHEESE
Creature23 the Demon________62____CHEESE || Creature23 the Superdemon_________0______MAYO

Creature23 WON THE ROUND!
Creature23 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 24
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature24 the Superdemon________28______MAYO || Creature24 the Demon________59____CHEESE
Creature24 the Demon________42____CHEESE || Creature24 the Superdemon_________0______MAYO

Creature24 WON THE ROUND!
Creature24 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TURN 25
ATTACKER______DAMAGE______TEAM || ATTACKER______HEALTH______TEAM

Creature25 the Superdemon________73______MAYO || Creature25 the Superdemon_________0____CHEESE

Creature25 WON THE ROUND!
Creature25 HAS 0 HEALTH SO THEY LOST THE ROUND...
=================================================================

TEAM CHEESE WINS WITH 571 POINTS!
TEAM MAYO LOST WITH 488 POINTS...


Menu:
1. Print Armies
2. Play Battle Game
3. Exit

Input: 1
Name==========Health====Strength========Type===========
=======================================================
Creature1 ________75__________81________Superdemon_____
Creature2 _________0__________77________Demon__________
Creature3 _________0__________30________Elf____________
Creature4 ________62__________54________Superdemon_____
Creature5 ________16__________48________Demon__________
Creature6 _________0__________77________Superdemon_____
Creature7 _________0__________30________Elf____________
Creature8 ________89__________61________Elf____________
Creature9 ________42__________66________Demon__________
Creature10________24__________39________Superdemon_____
Creature11_________0__________39________Superdemon_____
Creature12________62__________56________Elf____________
Creature13_________0__________46________Superdemon_____
Creature14________33__________51________Elf____________
Creature15_________0__________74________Superdemon_____
Creature16_________0__________55________Superdemon_____
Creature17________38__________79________Superdemon_____
Creature18_________0__________30________Superdemon_____
Creature19_________0__________30________Elf____________
Creature20________48__________76________Elf____________
Creature21_________0__________77________Demon__________
Creature22_________0__________63________Elf____________
Creature23________23__________79________Demon__________
Creature24________59__________45________Demon__________
Creature25_________0__________61________Superdemon_____
=======================================================
Name==========Health====Strength========Type===========
=======================================================
Creature1 _________0__________82________Superdemon_____
Creature2 ________40__________78________Elf____________
Creature3 ________42__________37________Superdemon_____
Creature4 _________0__________55________Elf____________
Creature5 _________0__________47________Superdemon_____
Creature6 ________59__________73________Elf____________
Creature7 ________39__________35________Demon__________
Creature8 _________0__________84________Superdemon_____
Creature9 _________0__________35________Superdemon_____
Creature10_________0__________42________Demon__________
Creature11________32__________79________Elf____________
Creature12_________0__________49________Superdemon_____
Creature13________23__________70________Superdemon_____
Creature14_________0__________89________Elf____________
Creature15________64__________72________Elf____________
Creature16________39__________41________Demon__________
Creature17_________0__________31________Elf____________
Creature18________16__________35________Elf____________
Creature19________19__________82________Demon__________
Creature20_________0__________88________Elf____________
Creature21________66__________87________Demon__________
Creature22________15__________54________Demon__________
Creature23_________0__________43________Superdemon_____
Creature24_________0__________31________Superdemon_____
Creature25________34__________74________Superdemon_____
=======================================================


Menu:
1. Print Armies
2. Play Battle Game
3. Exit

Input: 3

C:\Users\Matteo\source\repos\battlethingabstract\x64\Debug\battlethingabstract.exe (process 46264) exited with code 0.
Press any key to close this window . . .
*/