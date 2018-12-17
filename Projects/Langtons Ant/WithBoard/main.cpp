/******************************************************************************
 ** Program name: Langton's Ant
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Description: main function to initialize menu functions
 ** contains program blurb to be displayed one time
******************************************************************************/

#include "AntMenu.hpp"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

int main() {
    // intialize random seed for all rand operations
	srand(time(NULL));

    // intro blurb for program
	cout << "Welcome to Langton's Ant Simulator!" << endl <<
		"In this game, an ant is placed on a solid white board. With each step, the ant follows 2 rules:" << endl <<
		"1) If the ant is on a white space, turn right 90 degrees and change the space to black." << endl <<
		"2) If the ant is on a black space, turn left 90 degrees and change the space to white." << endl <<
		"With this program, users can simulate the movements of the ant, and see the results " <<
		"on the board." << endl <<
		"You will have to make some decisions about the ant prior to starting the simulation such as" << endl <<
		"the dimensions of the board, starting direction of ant, and where you would like the ant to start. " << endl <<
		"You may choose the starting location, or choose it to be random." << endl;

	// start menu
	mainMenu();

	return 0;
}