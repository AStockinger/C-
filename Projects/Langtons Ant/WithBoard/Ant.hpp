/********************************************************************************
 ** Program name: Langton's Ant
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Description: Ant class specification
 ** Ant has a position and direction, and board to move on
 ** move function provides bounds checking
*********************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

// forward declaration
class Board;

enum direction {UP, RIGHT, DOWN, LEFT};

class Ant {
private:
	// space array to be the 'board' the ant will move on
	Board* board;
	// 'coordinates' to the ant, x is the row and y is the column
	int x, y;
	// direction of the ant
	direction dir;
public:
	// inputs for number of rows and cols, moves, start row, start col and start direction
	Ant(int, int, Board*);
	// destructor
	~Ant();
	// move function tells ant to make move based on current space conditions
	void move();
};
#endif