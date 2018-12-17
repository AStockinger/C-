/******************************************************************************
 ** Program name: Lab 3
 ** Author: Amy Stockinger
 ** Date: October 6, 2018
 ** Description: Loaded Die specification
 ** The roll and getType functions are modified from the Die class to reflect
 ** a biased die. getType will tag it as loaded, and roll has a slightly
 ** higher chance of returning a larger number
******************************************************************************/

#ifndef LOADED_DIE_HPP
#define LOADED_DIE_HPP

#include "Die.hpp"

class LoadedDie : public Die{
    public:
        // constructors and virtual destructor
        LoadedDie();
        LoadedDie(int);
        virtual ~LoadedDie();
        // rolls die, slightly biased
        int roll();
        // gets die type as a string
        string getType();
};
#endif