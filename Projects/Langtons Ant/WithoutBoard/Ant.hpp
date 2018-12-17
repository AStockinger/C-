/********************************************************************************
 ** Program name: Langton's Ant
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Description: Ant class specification
*********************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Space.hpp"

enum direction {UP, RIGHT, DOWN, LEFT};

class Ant {
private:
	// BOARD specifics:
	// space array to be the 'board' the ant will move on
	Space** board;
	// represent the rows and columns of the board
	int rows, columns;
	// 'moves' for user input of desired number of moves and 'totalMoves as a counter
	int moves, totalMoves;

	// ANT specifics:
	// 'coordinates' to the ant, x is the row and y is the column
	int x, y;
	// direction of the ant
	direction dir;
public:
	// inputs for number of rows and cols, moves, start row, start col and start direction
	Ant(int, int, int, int, int);
	// destructor
	~Ant();
	// move function tells ant to make move based on current space conditions
	void move();
	// prints boards
	void printBoard();
};
#endif