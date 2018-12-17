/******************************************************************************
 ** Program name: Langton's Ant
 ** Author: Amy Stockinger
 ** Date: 9/20/18
 ** Description: Board class implementation
 ** Builds the board, an ant, and starts the simulation based on user input
 ** for number of rows, columns and turns, as well as ant starting position
******************************************************************************/

#include "Board.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

// constructor takes in num rows, num cols, num moves, and ant starting position coordinates
Board::Board(int r, int c, int m, int x, int y){
	rows = r;
    columns = c;
    moves = m;
    antX = x;
    antY = y;

    // start total moves made counter at 0
	int totalMoves = 0;

    Ant a(x, y, this);

	// create dynamic array board based on dimension inputs
	board = new Space*[rows];
	for (int i = 0; i < rows; i++) {
		board[i] = new Space[columns];
	}

	// print initial board;
	printBoard();

	// make moves until totalMoves = moves
	// print board after each move
	while (totalMoves < moves) {
		a.move();
		printBoard();
		totalMoves++;
	}
}

// destructor to prevent memory leaks
Board::~Board(){
    for (int i = 0; i < rows; i++) {
		delete[] board[i];
	}
	delete[] board;
	board = NULL;
}

// print current board
void Board::printBoard(){
	// top border
	cout << ".";
	for(int j = 0; j < columns; j++){
		cout << "--";
	}
	cout << ".";
	cout << endl;
	// place * where the ant is and # for black tiles
	for (int i = 0; i < rows; i++) {
		cout << "|";
		for (int j = 0; j < columns; j++) {
			if (i == antX && j == antY) {
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

// row and column getters for bounds checking in Ant move function
int Board::getRows(){
    return rows;
}
int Board::getCols(){
    return columns;
}

// sets ant on the given coordinates
void Board::setAntPos(int a, int b){
    antX = a;
    antY = b;
}

// returns a board Space for the inputted coordinates
Space Board::getSpace(int a, int b){
    return board[a][b];
}

// space color getter/setter for board
colorState Board::getSpaceColor(int a, int b){
    return board[a][b].getColor();
}
void Board::setSpaceColor(int a, int b, colorState c){
    board[a][b].setColor(c);
}