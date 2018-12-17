/********************************************************************************
 ** Program name: Langton's Ant
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Description: Ant class implementation 
 ** The Ant constructor starts at given coordinates with a set direction
 ** the move function considers current space color and position to put the ant
 ** on a new space on the board
*********************************************************************************/

#include "Ant.hpp"
#include "Board.hpp"

// constructor sets up the board and the ant
Ant::Ant(int startX, int startY, Board* b) {
	x = startX;
	y = startY;
	board = b;
	dir = UP;
}

// destructor
Ant::~Ant() {
}

// function will move ant according to rules, includes bounds checking
void Ant::move() {
	// determine which 'color' space the ant is currently on
	switch (board->getSpaceColor(x, y)){
		// if white, make the appropriate move and then change the space color
		case WHITE:
			// 90deg right depending on starting direction
			switch (dir) {
			case UP: dir = RIGHT;
				break;
			case RIGHT: dir = DOWN;
				break;
			case DOWN: dir = LEFT;
				break;
			case LEFT: dir = UP;
				break;
			}
			// switch space color before moving
			board->setSpaceColor(x, y, BLACK);
			break;
			// if black, make the appropriate move and then change the space color
		case BLACK:
			// 90deg left depending on starting direction
			switch (dir) {
			case UP: dir = LEFT;
				break;
			case RIGHT: dir = UP;
				break;
			case DOWN: dir = RIGHT;
				break;
			case LEFT: dir = DOWN;
				break;
			}
			// switch space color before moving
			board->setSpaceColor(x, y, WHITE);
			break;
	}

	// now modify x or y according to dir, still making sure it's in bounds before changing
	// The ant will move to the other side of the board if it is about to go out of bounds
	if (dir == UP){
		if(x > 0 && x <= (board->getRows() - 1)){
			x--;
		}
		else if(x == 0){
			x = board->getRows() - 1;
		}
	}
	else if (dir == DOWN){
		if(x >= 0 && x < (board->getRows() - 1)){
			x++;
		}
		else if(x == (board->getRows() - 1)){
			x = 0;
		}
	}
	else if (dir == RIGHT){
		if(y >= 0 && y < (board->getCols() - 1)){
			y++;
		}
		else if(y == (board->getCols() - 1)){
			y = 0;
		}
	}
	else if (dir == LEFT){
		if(y > 0 && y <= (board->getCols() - 1)){
			y--;
		}
		else if(y == 0){
			y = board->getCols() - 1;
		}
	}
	// place ant on new space
	board->setAntPos(x, y);
}