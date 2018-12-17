/********************************************************************* 
** Program name: Zoo Tycoon
** Author: Amy Stockinger
** Date: Oct 8, 2018
** Description: Menu implementation
*********************************************************************/

#include <iostream>
#include <string>
#include "ZooMenu.hpp"
#include "InputVal.hpp"

using std::cout;
using std::endl;
using std::string;

// display menu options and validate input option
void mainMenu(){
	// print menu for user with numbered options
	cout << "Please select an option by entering an integer:" << endl <<
		"1. Start Zoo Tycoon simulation" << endl <<
		"2. Quit" << endl;

	// get user option
    int option;
	getInt(option, 1, 2);

    if(option == 2){
        return;
    }
    else{
        startMenu();
    }
}

void startMenu(){
    Zoo zoo;
    zoo.startGame();
}