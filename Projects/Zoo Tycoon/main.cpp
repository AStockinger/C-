/********************************************************************* 
** Program name: Zoo Tycoon
** Author: Amy Stockinger
** Date: Oct 8, 2018
** Description: main function to start program
*********************************************************************/

#include "ZooMenu.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

int main(){
    // initialize random seed
    srand(time(NULL));

    cout << "**EC: User can choose food type daily." << endl;
    cout << "**EC: Random event messages are printed from a text file." << endl;
    cout << endl;

    // intro blurb
    cout << "Welcome to Zoo Tycoon. In this game, you may purchase tigers, penguins and turtles to care for " <<
    "in your own zoo." << endl;
    cout << "It is your job to feed and care for aging animals while managing zoo cashflow." << endl;
    cout << "You are able to purchase up to two of each animal up front, and one per day thereafter." << endl;

    // display main menu options
    mainMenu();

    return 0;
}