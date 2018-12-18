/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Deck of Cards implementation. Makes a deck of cards in a
 ** vector container and will choose one at random to deal. playRound function
 ** will simulate a simple blackjack game.
******************************************************************************/

#include "deckOfCards.hpp"
#include "Card.hpp"
#include "InputVal.hpp"
#include <iostream>

using std::cout;
using std::endl;

// makes a deck of cards
DeckOfCards::DeckOfCards(){
    totalCards = 0;
    
    for(int j = 0; j < 4; j++){
        for(int k = 0; k < 13; k++){
            deck.push_back(new Card(k, j));
            totalCards++;
        }
    }
}

// delete deck
DeckOfCards::~DeckOfCards(){
    for(int i = 0; i < totalCards; i++){
        delete deck[i];
    }
}
        
Card* DeckOfCards::dealCard(){
    return deck[rand() % totalCards];
}

// returns true if player wins, and false if dealer wins
bool DeckOfCards::playBlackjackRound(){
    Hand player;
    Hand dealer;
    int hitOrStay = 1;
    int numCardsPlayer = 0;
    int numCardsDealer = 0;

    player.addCard(this->dealCard());
    dealer.addCard(this->dealCard());
    player.addCard(this->dealCard());
    numCardsPlayer += 2;
    numCardsDealer++;

    cout << "Here are your cards:" << endl;
    player.showCards();

    cout << "The dealer's face up card is:" << endl;
    dealer.showCards();

    while(hitOrStay == 1 && numCardsPlayer < 5){
        cout << "Do you want to (1) hit or (2) stay?" << endl;
        getInt(hitOrStay, 1, 2);

        if(hitOrStay == 1){
            player.addCard(this->dealCard());
            numCardsPlayer++;
            cout << "Here are your cards:" << endl;
            player.showCards();
        }
    }

    cout << "Your current cards and value is:" << endl;
    player.showCards();
    cout << "Value: " << player.countCards() << endl;

    dealer.addCard(this->dealCard());
    numCardsDealer++;
    while(dealer.countCards() < 15 && numCardsDealer < 5){
        dealer.addCard(this->dealCard());
        numCardsDealer++;
    }
    cout << "The dealer reveals his cards: " << endl;
    dealer.showCards();
    cout << "Value: " << dealer.countCards() << endl;

    // can't have more than 21
    if(player.countCards() > 21){
        cout << "You went over 21. You lost your bet." << endl;
        return false;
    }
    else if(dealer.countCards() > 21){
        cout << "The dealer went over 21. You win!" << endl;
        return true;
    }
    // dealer wins if you don't beat his hand
    else if(dealer.countCards() > player.countCards() || dealer.countCards() == player.countCards()){
        cout << "The dealer wins!" << endl;
        return false;
    }
    // player wins
    else if(player.countCards() == 21){
        cout << "You have 21! You win" << endl;
        return true;
    }
    else{
        cout << "You win!" << endl;
        return true;
    }
}