/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Space specification
******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "InputVal.hpp"

// forward declaration
class Player;

class Space{
    protected:
        Space *up;
        Space *right;
        Space *down;
        Space *left;
    public:
        Space();
        virtual ~Space();
        virtual void interact(Player*) = 0;
        virtual bool gameWon() = 0;
        // space getters and setters for adjacent spaces
        Space* getUp();
        Space* getRight();
        Space* getDown();
        Space* getLeft();
        void setUp(Space*);
        void setRight(Space*);
        void setDown(Space*);
        void setLeft(Space*);
};
#endif