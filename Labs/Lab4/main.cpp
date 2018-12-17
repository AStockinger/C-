/********************************************************************* 
** Program name: Lab 4
** Author: Amy Stockinger
** Date: 10/14/18
** Description: main function to introduce and start the program
*********************************************************************/

#include "Menu.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;

int main(){
    // initialize random seed
    srand(time(NULL));

    // intro blurb
    cout << "Welcome to Oregon State University!" << endl;
    cout << "With this program, you can generate campus buildings, students, and instructors." << endl;
    cout << "You can also pick a random person and see how much work they did today." << endl;

    // display main menu options
    mainMenu();

    return 0;
}