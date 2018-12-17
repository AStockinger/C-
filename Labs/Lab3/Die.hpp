/******************************************************************************
 ** Program name: Lab 3
 ** Author: Amy Stockinger
 ** Date: October 6, 2018
 ** Description: Die class specification
** Class simulates a game die by taking in a number to represent sides,
 ** and returns a random number between 1 and sides with the roll function.
******************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <string>

using std::string;

class Die{
    protected:
        // number of sides on a die
        int N;
    public:
        // constructors
        Die();
        Die(int);
        virtual ~Die();
        // roll function returns a number between 1 and N
        virtual int roll();
        // get sides
        int getSides();
        // get type
        virtual string getType();
};
#endif