/******************************************************************************
 ** Program name: Langton's Ant
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Description: Board class specification file
 ** includes variables to create a dynamic board and track ant position
 ** getter/setter functions for use in Ant class move function
******************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Space.hpp"
#include "Ant.hpp"

class Board{
    private:
        // board is a dynamic array of spaces
        Space** board;
        // user input variables for game customization
        int rows, columns, moves;
        // ant position
        int antX, antY;
    public:
        // constructor takes in user input vars for board size, num moves and ant start pos
        Board(int, int, int, int, int);
        ~Board();
        // print current board
        void printBoard();
        // row and column getters for bounds checking
        int getRows();
        int getCols();
        // ant position setter
        void setAntPos(int, int);
        // returns space on board for given coordinates
        Space getSpace(int, int);
        // space color getter and setter
        colorState getSpaceColor(int, int);
        void setSpaceColor(int, int, colorState);
};
#endif