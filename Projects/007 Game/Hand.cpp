/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Hand implementation, to represent the cards in a player's 
 ** hand during blackjack. Includes functions to count the cards and 
******************************************************************************/

#include "Hand.hpp"
#include <iostream>

using std::cout;
using std::endl;

// player starts with an empty hand
Hand::Hand(){
    for(int i = 0; i < 5; i++){
        hold[i] = nullptr;
    }
}

// counts cards in hand, and adjusts for aces
int Hand::countCards(){
    int total = 0;
    bool ace = false;
    bool twoAces = false;
    bool threeAces = false;
    for(int i = 0; i < 5; i++){
        if(hold[i] != nullptr){
            if(hold[i]->getValue() == 11){
                if(twoAces == true){
                    threeAces = true;
                }
                else if(ace == true){
                    twoAces = true;
                }
                ace = true;
            }
            total += hold[i]->getValue();
        }
    }
    // adjust for aces
    if(total > 21 && threeAces == true){
        total -= 10;
    }
    if(total > 21 && twoAces == true){
        total -= 10;
    }
    if(total > 21 && ace == true){
        total -= 10;
    }
    return total;
}

// add one card to the hand
void Hand::addCard(Card* c){
    for(int i = 0; i < 5; i++){
        if(hold[i] == NULL){
            hold[i] = c;
            return;
        }
    }
}

// prints out cards in current hand
void Hand::showCards(){
    for(int i = 0; i < 5; i++){
        if(hold[i] != NULL){
            hold[i]->printCard();
            cout << endl;
        }
        else{
            break;
        }
    }
    cout << endl;
    return;
}