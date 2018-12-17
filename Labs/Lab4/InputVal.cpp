/******************************************************************************
 ** Program name: Lab 4
 ** Author: Amy Stockinger
 ** Date: 10/13/18
 ** Description: input validation function takes a reference variable and 
 ** two ints for the range that the variable is allowed to be in
 ** function will reprompt until an acceptable integer is inputted
******************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using std::cin;
using std::string;
using std::cout;
using std::stringstream;

// input takes a number variable to be changed, along with min and max acceptable values
int getInt(int &value, int min, int max){
    string s;
    do{
        cout << "Please enter an integer between " << min << " and " << max << ": ";
        string line;
        getline(cin, line);
        // change string to int
        stringstream ss(line);
        ss >> value;
        // check line for numbers
        for(unsigned int i = 0; i < line.length(); i++){
            if(!isdigit(line[i])){
                value = min - 1;
            }
        }
    }while(value == 0 || value > max || value < min);

    return value;
}