/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Deck of Cards specification file, makes a card deck and
 ** simulates blackjack.
******************************************************************************/

#ifndef DECK_OF_CARDS_HPP
#define DECK_OF_CARDS_HPP

#include "Hand.hpp"
#include <vector>

using std::vector;

class DeckOfCards{
    private:
        // card container
        vector<Card*> deck;
        // keeps track of how many cards are in the deck
        int totalCards;
    public:
        // constructor makes a deck of cards
        DeckOfCards();
        ~DeckOfCards();
        // randomly picks a card from the deck
        Card* dealCard();
        // simulates blackjack
        bool playBlackjackRound();
};
#endif