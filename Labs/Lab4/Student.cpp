/********************************************************************* 
** Program name: Lab 4
** Author: Amy Stockinger
** Date: 10/13/18
** Description: Student implementation file, derived from People
** includes overridden functions to do work, and return GPA-related
** information
*********************************************************************/

#include "Student.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::endl;

Student::Student() : Person(){
    // randomly generates a GPA in constructor
    GPA = (4.0 - 0.0) * ((double)rand() / (double)RAND_MAX);
    int realistic = rand() % 3;

    if(realistic > 0 && GPA < 2.5){
        GPA += 1.0;
    }
}

Student::~Student(){}

// prints statement with random number of hours of homework done
void Student::do_work(){
    int num = rand() % 20;
    cout << getName() << " did " << num << " hours of homework." << endl;
    cout << endl;
}
// returns GPA
double Student::getInfo(){
    return GPA;
}
// string related to getInfo printout
string Student::ending(){
    return " GPA.";
}