/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Game specification file, manages starting the game and
 ** the main game menu, printing the board, and tracking location
******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "InputVal.hpp"
#include "Player.hpp"
#include "Bar.hpp"
#include "Slots.hpp"
#include "Roof.hpp"
#include "Blackjack.hpp"
#include "Exclusive.hpp"
#include "Roulette.hpp"

class Game{
    private:
        // bool 
        bool gamePlay;
        // player pointer for player
        Player *player;
        // space pointers for each space on the map
        Space* roof;
        Space* bar;
        Space* roulette;
        Space* exclusive;
        Space* blackjack;
        Space* slots;
    public:
        Game();
        virtual ~Game();
        void startGame();
        void printMap();
};
#endif