/********************************************************************* 
** Program name: Fantasy Combat
** Author: Amy Stockinger
** Date: 10/21/18
** Description: Fantasy Menu implementation
** start or quit program
** allows user to pick 2 fighters and starts the simulation
*********************************************************************/

#include "InputVal.hpp"
#include "Game.hpp"
#include "gameMenu.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void mainMenu(){
    int option;

    // print initial menu for user with numbered options
	cout << "Please select an option by entering an integer:" << endl <<
		"1. Start Battle" << endl <<
		"2. Quit" << endl;

	getInt(option, 1, 2);

	// input option into menu
	startMenu(option);
}

// allows user to pick 2 fighters and starts the simulation
void startMenu(int option){
    switch (option){
        case 1:
            selectCharacters();
            mainMenu();
        break;
        case 2:
            exit(0);
            break;
    }
}