/******************************************************************************
 ** Program name: Lab 3
 ** Author: Amy Stockinger
 ** Date: October 6, 2018
 ** Description: Game class specification
 ** Makes a game that allows a user to customize dice for each of two players,
 ** and choose a number of turns for the dice to be rolled against each other.
 ** The final scores are printed along with the winner at the end of the dice
 ** roll game simulation.
******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "LoadedDie.hpp"

class Game{
    private:
        // each players points
        int pointsP1, pointsP2;
        // pointers to players dice
        Die* player1;
        Die* player2;
    public:
        Game();
        // options to play or quit
        void mainMenu();
        // takes in user inputs for dice to set up game
        void play();
        // takes 2 die pointers and compares a dice roll
        void compareDice(Die*, Die*);
        // point getters and setters for the players
        void setP1Points(int);
        int getP1Points();
        void setP2Points(int);
        int getP2Points();
};
#endif