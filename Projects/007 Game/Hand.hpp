/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Hand class specification
 ** represents a hand of cards in a blackjack game
******************************************************************************/

#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include <string>

using std::string;

class Hand{
    private:
        Card* hold[5];
    public:
        Hand();
        int countCards();
        void addCard(Card*);
        void showCards();
};
#endif