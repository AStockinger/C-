/******************************************************************************
 ** Program name: Langton's Ant
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Description: user menu for Langton's Ant simulation
 ** includes a main menu with "quit" option and a secondary menu to
 ** set up the board if the user chooses the play
 ** allows RNG for ant starting location, or the user may choose
******************************************************************************/

#include "AntMenu.hpp"
#include "InputVal.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;


// display main menu options and validate input option
void mainMenu() {
	int option = 0;

	// print menu for user with numbered options
	cout << "What would you like to do? Select an option." << endl <<
		"1. Start Langton's Ant simulation" << endl <<
		"2. Quit" << endl;

	getInt(option, 1, 2);

	// input option into secondary menu for user program customization
	if(option == 1){
		customMenu();
	}

	else{
		return;
	}
}

// execute menu option
void customMenu(){

	int row, col, numMoves, startX, startY, randOrNot; 	// variables to be used in menu options

	cout << "How many rows would you like the ant to move through?" << endl;
	getInt(row, 1, 500);

	cout << "How many columns would you like the ant to move through?" << endl;
	getInt(col, 1, 500);

	cout << "How many moves should the ant make?" << endl;
	getInt(numMoves, 0, 200000);

	cout << "Would you like to:" << endl <<
		"1. Randomly place the ant in a starting position" << endl <<
		"2. Choose a starting position" << endl;
	getInt(randOrNot, 1, 2);

	// randomly place ant according to board dimensions
	if (randOrNot == 1) {
		startX = rand() % row;
		startY = rand() % col;
	}
	// or user may enter coordinates, with input validation
	else {
		cout << "What row should the ant start in?" << endl;
		getInt(startX, 0, row - 1);
		cout << "What column should the ant start in?" << endl;
		getInt(startY, 0, col - 1);
	}

	Board (row, col, numMoves, startX, startY);
	
	mainMenu();
}