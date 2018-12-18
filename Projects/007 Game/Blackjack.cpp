/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Blackjack implementation, starts a game of blackjack with
 ** the player, with chances for random event/item
******************************************************************************/

#include "Blackjack.hpp"
#include "Player.hpp"
#include "deckOfCards.hpp"
#include "ExclusiveInvite.hpp"
#include "CommDevice.hpp"
#include <iostream>
using std::cout;
using std::endl;

Blackjack::Blackjack() : Space(){
    invite = new ExclusiveInvite();
}

Blackjack::~Blackjack(){
    delete invite;
}

void Blackjack::interact(Player* player){
    bool playing = true;
    int choice, bet;
    DeckOfCards d;

    cout << "You spot a lively group at the Blackjack table. Do you appraoch? Enter 1 to play." << endl;
    getInt(choice, 1, 2);
    if(choice == 2){
        playing = false;
    }

    while(playing){
        cout << "How much are you betting on this round?" << endl;
        getInt(bet, 1000, 5000); // get bet
        // play game
        if(d.playBlackjackRound() == true){
            player->setMoney(player->getMoney() + (bet * 5));
            cout << "Your total money is now: " << player->getMoney() << endl;

            int chance = -1;

            if(player->getInventory()->hasItem(EXCLUINV) == false && player->getInventory()->hasItem(COMMDEV) == true){
                // assign random value to chance
                chance = rand() % 4;
                // give out invite based on chance
                if(chance == 0){
                    player->getInventory()->addItem(*invite);
                    player->getInventory()->getItem(EXCLUINV)->message();
                }
                if(chance == 2){
                    player->getInventory()->getItem(COMMDEV)->message();
                }
            }
        }
        // player can stay or move on
        cout << "Do you: 1. stay and play or 2. leave the table?" << endl;
        getInt(choice, 1, 2);
        if(choice == 2){
            playing = false;
        }
    }
}