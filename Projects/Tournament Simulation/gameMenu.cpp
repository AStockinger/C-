/********************************************************************* 
** Program name: Fantasy Combat Tournament
** Author: Amy Stockinger
** Date: 11/5/18
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
		"1. Start Tournament" << endl <<
		"2. Quit" << endl;

	getInt(option, 1, 2);

	// input option into menu
    if(option == 1){
	    startMenu();
    }
    else{
        return;
    }
}

// allows user to pick 2 fighters and starts the simulation
void startMenu(){
    Game();

    mainMenu();
}