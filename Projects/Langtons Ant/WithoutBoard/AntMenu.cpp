/******************************************************************************
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Program name: Langton's Ant Menu
 ** Description: user menu for Langton's Ant simulation
 ** allows RNG for ant starting location, or the user may choose
******************************************************************************/

#include "AntMenu.hpp"
#include <iostream>
#include <time.h>
#include <limits>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

// display main menu options and validate input option
void menuDisplay() {
	// variable for user option choice and total options available
	int option;
	int totalOptions = 2;

	// print menu for user with numbered options
	cout << "What would you like to do? Please select an option by entering an integer." << endl <<
		"1. Start Langton's Ant simulation" << endl <<
		"2. Quit" << endl;

	// get user option
	cin >> option;

	// validate user option
	while (cin.fail() || option < 1 || option > totalOptions) {
		cout << "Please enter a valid menu choice." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> option;
	}

	// input option into secondary menu for user program customization
	menu(option);

	//display menu again
	menuDisplay();
}

// execute menu option
void menu(int option){

	// variables to be used in menu options
	int row, col, numMoves, startX, startY, randOrNot, dir;
	direction startDir;

	switch (option) {
		// option 1 gathers info from user, validates and then runs program
		case 1:
			cout << "How many rows would you like the ant to move through?" << endl;
			cin >> row;
			// row cannot be 0 or negative
			while (cin.fail() || row < 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a positive integer." << endl;
				cin >> row;
			}
			cout << "How many columns would you like the ant to move through?" << endl;
			cin >> col;
			// col cannot be 0 or negative
			while (cin.fail() || col < 1) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a positive integer." << endl;
				cin >> col;
			}
			cout << "How many moves should the ant make?" << endl;
			cin >> numMoves;
			// ant cannot make negative moves
			while (cin.fail() || numMoves < 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a positive integer." << endl;
				cin >> numMoves;
			}
			cout << "Would you like to:" << endl <<
				"1. Randomly place the ant in a starting position" << endl <<
				"2. Choose a starting position" << endl;
			cin >> randOrNot;
			while (cin.fail() || randOrNot < 0 || randOrNot > 2){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a valid option." << endl;
				cin >> randOrNot;
			}
			// randomly place ant according to board dimensions
			if (randOrNot == 1) {
				startX = rand() % row;
				startY = rand() % col;
			}
			// or user may enter coordinates, with input validation
			else {
				cout << "What row should the ant start in?" << endl;
				cin >> startX;
				while (cin.fail() || startX < 0 || startX > row - 1){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please enter valid row number." << endl;
					cin >> startX;
				}
				cout << "What column should the ant start in?" << endl;
				cin >> startY;
				while (cin.fail() || startY < 0 || startY > col - 1){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please enter valid column number." << endl;
					cin >> startY;
				}
			}
			Ant(row, col, numMoves, startX, startY);
			break;
		// option 2 to exit
		case 2:
			exit(0);
			break;
		default:
			break;
	}
}