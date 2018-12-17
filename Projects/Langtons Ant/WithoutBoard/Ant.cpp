/********************************************************************************
 ** Program name: Langton's Ant
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Description: Ant class implementation 
 ** This class builds both the Ant and the board the Ant moves on.
 ** The Ant constructor builds the simulation loop and prints the board at each
 ** step of the ant.
*********************************************************************************/

#include <iostream>
#include <cstdlib>
#include "Ant.hpp"

using std::cout;
using std::endl;

// constructor sets up the board and the ant
Ant::Ant(int row, int col, int steps, int startX, int startY) {
	rows = row;
	columns = col;
	moves = steps;
	x = startX;
	y = startY;
	dir = UP;

	// start total moves counter at 0
	totalMoves = 0;

	// create dynamic array board based on dimension inputs
	board = new Space*[rows];
	for (int i = 0; i < rows; i++) {
		board[i] = new Space[columns];
	}

	// place ant on board at specified coordinate
	board[x][y].setAnt(true);

	// print initial board;
	printBoard();

	// make moves until totalMoves = moves
	// print board after each move
	while (totalMoves < moves) {
		move();
		printBoard();
		totalMoves++;
	}
}

// destructor to prevent memory leaks
Ant::~Ant() {
	for (int i = 0; i < rows; i++) {
		delete[] board[i];
	}
	delete[] board;
	board = NULL;
}

// function will move ant according to rules, includes bounds checking
void Ant::move() {
	// determine which 'color' space the ant is currently on
	switch (board[x][y].getColor()) {
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
			board[x][y].setColor(BLACK);
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
			board[x][y].setColor(WHITE);
			break;
	}
	// remove ant from the previous spot
	board[x][y].setAnt(false);
	// The ant will move to the other side of the board if it is about to go out of bounds
	// now modify x or y according to dir, still making sure it's in bounds before changing
	if (dir == UP){
		if(x > 0 && x <= (rows - 1)){
			x--;
		}
		else if(x == 0){
			x = rows - 1;
		}
	}
	else if (dir == DOWN){
		if(x >= 0 && x < (rows - 1)){
			x++;
		}
		else if(x == (rows - 1)){
			x = 0;
		}
	}
	else if (dir == RIGHT){
		if(y >= 0 && y < (columns - 1)){
			y++;
		}
		else if(y == (columns - 1)){
			y = 0;
		}
	}
	else if (dir == LEFT){
		if(y > 0 && y <= (columns - 1)){
			y--;
		}
		else if(y == 0){
			y = columns - 1;
		}
	}
	// place ant on new space
	board[x][y].setAnt(true);
}

// function to print the current board with border     
void Ant::printBoard() {
	// top border
	cout << ".";
	for(int j = 0; j < columns; j++){
		cout << "--";
	}
	cout << ".";
	cout << endl;
	// cycle through the board and place * where the ant is and # for black tiles
	for (int i = 0; i < rows; i++) {
		cout << "|";
		for (int j = 0; j < columns; j++) {
			if (board[i][j].getAnt()) {
				cout << '*' << ' ';
			}
			else if (board[i][j].getColor() == 1) {
				cout << '#' << ' ';
			}
			else{
				cout << "  ";
			}
		}
		cout << "|";
		cout << endl;
	}
	// bottom border
	cout << ".";
	for(int j = 0; j < columns; j++){
		cout << "--";
	}
	cout << ".";
	cout << endl;
	cout << endl;
}