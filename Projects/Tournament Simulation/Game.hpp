/********************************************************************* 
** Program name: Fantasy Combat Tournament
** Author: Amy Stockinger
** Date: 11/5/18
** Description: Game class specification
** includes a loserstack, two characterqueues, team scoring, 
** and necessary driver functions
*********************************************************************/

#include "Character.hpp"
#include "CharacterQueue.hpp"
#include "LoserStack.hpp"

#ifndef GAME_HPP
#define GAME_HPP

class Game{
    private:
        CharacterQueue* One;        // team one's character lineup
        CharacterQueue* Two;        // team two's character lineup
        LoserStack* losers;         // shared loser pile
        int rounds;                 // keeps track of rounds in the game
        int teamOne, teamTwo;       // keeps track of number of characters on each team
        int scoreOne, scoreTwo;     // keeps track of team scores
    public:
        Game();
        ~Game();
        // selects a character and name to add to the inputted queue
        void selectCharacter(CharacterQueue*);
        // manages tournament game and gives final score
        void initialize();
        // determines winner of the rounds
        void fightChars();
};
#endif
