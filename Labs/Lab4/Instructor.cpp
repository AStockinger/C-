/********************************************************************* 
** Program name: Lab 4
** Author: Amy Stockinger
** Date: 10/13/18
** Description: Instructor implementation file, derived from People
** includes overridden functions to do work, and return rating-related
** information
*********************************************************************/

#include "Instructor.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;

Instructor::Instructor() : Person(){
    rating = (5.0 - 0.0) * ((double)rand() / (double)RAND_MAX);
}

Instructor::~Instructor(){}

// prints work statement with a random number of hours
void Instructor::do_work(){
    int num;
    num = rand() % 20;
    cout << getName() << " graded papers for " << num << " hours." << endl;
    cout << endl;
}

// get rating
double Instructor::getInfo(){
    return rating;
}

// specifier for getInfo function
string Instructor::ending(){
    return " rating.";
}