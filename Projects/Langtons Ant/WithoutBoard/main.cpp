#include "AntMenu.hpp"
#include <iostream>
#include <time.h>
#include <limits>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

int main() {
    // intialize random seed for all rand operations
	srand(time(NULL));

    // intro blurb for program
	cout << "Welcome to Langton's Ant Simulator!" << endl <<
		"With this program, users can simulate the movements of the ant, and see the results " <<
		"on the board." << endl <<
		"You will have to make some decisions about the ant prior to starting the simulation such as" << endl <<
		"the dimensions of the board, starting direction of ant, and where you would like the ant to start. " << endl <<
		"You may choose the starting location, or choose it to be random." << endl;

	// start menu
	menuDisplay();

	return 0;
}