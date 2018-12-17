/******************************************************************************
 ** Program name: Lab 3
 ** Author: Amy Stockinger
 ** Date: October 6, 2018
 ** Description: Loaded Die specification
 ** The roll and getType functions are modified from the Die class to reflect
 ** a biased die. getType will tag it as loaded, and roll has a slightly
 ** higher chance of returning a larger number
******************************************************************************/

#include "LoadedDie.hpp"
#include <stdlib.h>
#include <time.h>

LoadedDie::LoadedDie() : Die(){}

LoadedDie::LoadedDie(int a) : Die(a){}

LoadedDie::~LoadedDie(){}

int LoadedDie::roll(){
    // make a random number for chance of bias
    int bias = rand() % 5;

    // bias gives 2/5 chance of "biased roll", which will be at least equal to half of N
    if(bias == 0 || bias == 2 || bias == 4){
        int value = ((rand() % (N / 2)) + 1) + (N / 2);
        if(value > N){
            value = N;
        }
        return value;
    }
    // 3/5 chance of unbiased roll
    else{
        return (rand() % N) + 1;
    }
}

// returns die type as a string
string LoadedDie::getType(){
    return "loaded";
}