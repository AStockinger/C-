/********************************************************************************
** Program Name: Matrix Calculator
** Author: Amy Stockinger
** Date: 9/20/18
** Description: main.cpp file with user directives
** prints matrix, as inputted by user, and determinant
*********************************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::numeric_limits;
using std::streamsize;

int main(){

    int choice, size, num;

    cout << "Thank you for using the Matrix Calculator." << endl;
    cout << "Please input a matrix and the determinant will be returned." << endl;
    cout << "What size matrix are you working with? Please enter an integer choice." << endl <<
    "1. 2x2" << endl <<
    "2. 3x3" << endl;

    cin >> choice;

    // validate choice
    while(cin.fail() || choice > 2 || choice < 1){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a valid choice." << endl;
        cin >> choice;
    }
    if(choice == 1){
        size = 2;
    }
    else{
        size = 3;
    }

    // create matrix
    int** matrix = new int*[size];
    for(int i = 0; i < size; ++i){
        matrix[i] = new int[size];
    }

    // function to take inputs
    cout << "Please note: as numbers are inputted, they will go across the rows." << endl;
    readMatrix(size, matrix);

    // print matrix with some formatting
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << setw(10) << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    // print determinant
    cout << "The determinant is: " << determinant(size, matrix) << endl;

    // deallocate and prevent memory leaks
    for(int i = 0; i < size; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}