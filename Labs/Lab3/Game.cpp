/******************************************************************************
 ** Program name: Lab 3
 ** Author: Amy Stockinger
 ** Date: October 6, 2018
 ** Description: Game class implementation
 ** Makes a game that allows a user to customize dice for each of two players,
 ** and choose a number of turns for the dice to be rolled against each other.
 ** The final scores are printed along with the winner at the end of the dice
 ** roll game simulation.
******************************************************************************/

#include "Game.hpp"
#include "InputVal.hpp"
#include <iostream>
#include <limits.h>

using std::cout;
using std::endl;

// constructor sets points at 0 and initializes game
Game::Game(){
    pointsP1 = 0;
    pointsP2 = 0;
    player1 = nullptr;
    player2 = nullptr;
    mainMenu();
}

// main menu presents option to play or quit
void Game::mainMenu(){
    // variable for user option choice and total options available
	int option;

	// print menu for user with numbered options
	cout << "Please select an option by entering an integer:" << endl <<
		"1. Start 'War' Game" << endl <<
		"2. Quit" << endl;

	// get user option
	getInt(option, 1, 2);

    if(option == 1){
        play();
    }
    else{
        exit(0);
    }
}

// takes in user customizations and reports results of game
void Game::play(){
    int rounds, type1 = 0, type2 = 0, sides1 = 0, sides2 = 0;

    // how many turns, and a disclaimer in case program lags if number toward INT_MAX is chosen
    cout << "How many rounds will be played?" << endl;
    cout << "If you enter a very high number, it may take a minute." << endl;
    getInt(rounds, 1, INT_MAX);

    cout << endl;

    // get Player 1 dice info
    cout << "What type of die will Player 1 use? Enter 1 for Normal Die and 2 for Loaded Die." << endl;
    getInt(type1, 1, 2);
    cout << endl;   
    cout << "How many sides will Player 1's die have?" << endl;
    getInt(sides1, 2, INT_MAX);

    cout << endl;

    // get player 2 dice info
    cout << "What type of die will Player 2 use? Enter 1 for Normal Die and 2 for Loaded Die." << endl;
    getInt(type2, 1, 2);
    cout << endl;
    cout << "How many sides will Player 2's die have?" << endl;
    getInt(sides2, 2, INT_MAX);

    cout << endl;

    // make new die according to player selections
    if(type1 == 1){
        player1 = new Die(sides1);
    }
    else{
        player1 = new LoadedDie(sides1);
    }

    if(type2 == 1){
        player2 = new Die(sides2);
    }
    else{
        player2 = new LoadedDie(sides2);
    }

    // roll dice for each round
    for(int i = 0; i < rounds; i++){
        compareDice(player1, player2);
    }

    // announce winner
    cout << "Player 1 has " << getP1Points() << " points, and " <<
    "Player 2 has " << getP2Points() << " points." << endl;

    if(getP1Points() > getP2Points()){
        cout << "Player 1 wins!!" << endl;
    }
    else if(getP2Points() > getP1Points()){
        cout << "Player 2 wins!!" << endl;
    }
    else{
        cout << "It's a tie!" << endl;
    }
    cout << endl;

    // prevent memory leaks, reset points and ask to play again
    delete player1;
    delete player2;
    setP1Points(0);
    setP2Points(0);
    mainMenu();
}

// takes in two dice, rolls them and adds points for the winner
// no points awarded if a tie
void Game::compareDice(Die* a, Die* b){
    int turnA = a->roll();
    int turnB = b->roll();

    cout << "Player 1 used a " << a->getType() << " die with " << a->getSides() << " sides and rolled " << turnA << endl;
    cout << "Player 2 rolled " << b->getType() << " die with " << b->getSides() << " sides and rolled " << turnB << endl;

    if(turnA > turnB){
        setP1Points(getP1Points() + 1);
        cout << "Player 1 wins this round! Player 1's score is now " << getP1Points() << endl;
    }
    else if(turnB > turnA){
        setP2Points(getP2Points() + 1);
        cout << "Player 2 wins this round! Player 2's score is now " << getP2Points() << endl;
    }
    else{
        cout << "It's a tie! No points are awarded." << endl;
    }
}

// player points getters and setters
void Game::setP1Points(int a){
    pointsP1 = a;
}
int Game::getP1Points(){
    return pointsP1;
}
void Game::setP2Points(int a){
    pointsP2 = a;
}
int Game::getP2Points(){
    return pointsP2;
}