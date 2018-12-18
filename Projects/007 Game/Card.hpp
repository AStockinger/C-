/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Card specification file
******************************************************************************/

#ifndef CARD_HPP
#define CARD_HPP

// for reference purposes
enum suits {SPADES, HEARTS, CLUBS, DIAMONDS};
enum faces {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

class Card{
    private:
        int value;
        int face;
        int suit;
    public:
        Card();
        // card accepts 2 ints to represent face and suit, then assigns a value from that
        Card(int, int);
        // returns value of the card
        int getValue();
        // prints out what the card is
        void printCard();
};
#endif