/********************************************************************************
** Program Name: Matrix Calculator
** Author: Amy Stockinger
** Date: 9/20/18
** Description: readMatrix function implementation fills the matrix with user 
** inputted integers, with input validation
*********************************************************************************/

#include <iostream>
#include <limits>
#include "readMatrix.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

// takes user integer inputs to fill array
void readMatrix(int size, int** matrix){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << "Please enter an integer: ";
            cin >> matrix[i][j];
            // input validation
            while(cin.fail()){
                cout << "Please enter a valid integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> matrix[i][j];
            }
        }
    }
}