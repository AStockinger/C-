/********************************************************************* 
** Program name: Fantasy Combat
** Author: Amy Stockinger
** Date: 10/21/18
** Description: main function gives intro blurb and starts game
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "gameMenu.hpp"
using std::cout;
using std::endl;


int main(){

    // initialize random seed
    srand(time(NULL));

	// intro blurb for program
	cout << "*** Welcome to Fantasy Combat Game ***" << endl <<
    "You may choose two of the following types of characters to battle against each other." << endl <<
    "1. The Barbarian; Strength: 12, Armor: 0, Attack: 2d6, Defend: 2d6" << endl <<
    "2. The Blue Men; Strength: 12, Armor: 3, Attack: 2d10, Defend: 3d6" << endl <<
    "    These little blue men are small but vicious. Take one out, and their defense will fall." << endl <<
    "3. Harry Potter; Strength: 10, Armor: 0, Attack: 2d6, Defend: 2d6" << endl <<
    "    Do not be decieved by his underwhelming stats, Harry can regenerate with double health!" << endl << 
    "4. Medusa; Strength: 8, Armor: 3, Attack: 2d6, Defend: 1d6" << endl <<
    "    It is said that eye contact with a Medusa will turn the looker to stone." << endl <<
    "5. The Vampire; Strength: 18, Armor: 1, Attack: 1d12, Defend: 1d6" << endl <<
    "    Vampires are charming creatures, perhaps charming enough to avoid attack." << endl;

	// start menu
	mainMenu();

    return 0;
}