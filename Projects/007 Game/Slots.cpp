/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Slots implementation. Player can play slot games to win money.
 ** Also, there is potential to interact with special items to progress in the
 ** game.
******************************************************************************/

#include "Slots.hpp"
#include "ExclusiveInvite.hpp"
#include "CommDevice.hpp"
#include <iostream>
using std::cout;
using std::endl;

Slots::Slots() : Space(){
    invite = new ExclusiveInvite();
}

Slots::~Slots(){
    delete invite;
}

void Slots::interact(Player* p){
    bool playing = true;
    int play;
    cout << "Ah, the slot area. It is more secluded, but still offers large potential payouts." << endl;
    cout << "These are simple three-reel seven symbol machines." << endl;
    cout << "Do you want to play the slot machines? Enter 1 for YES or 2 for NO." << endl;
    getInt(play, 1, 2);
    if(play == 2){
        playing = false;
    }

    while(playing == true){
        int bet, playAgain;
        int random1 = rand() % 7;
        int random2 = rand() % 7; 
        int random3 = rand() % 7;

        cout << "How much would you like to bet?" << endl;
        getInt(bet, 100, 1000);

        // print 3 rolls
        cout << "The slots show: " << slotSymbol(random1) << " " << slotSymbol(random2) << " " << slotSymbol(random3) << endl;

        // if all equal
        if(random1 == random2 && random2 == random3){
            p->setMoney(p->getMoney() + (100 * bet));
            cout << "Three of a kind! You win " << 100 * bet << "!!" << endl;

            if(p->getInventory()->hasItem(EXCLUINV) == false && p->getInventory()->hasItem(COMMDEV) == true){
                p->getInventory()->addItem(*invite);
                p->getInventory()->getItem(EXCLUINV)->message();
            }
        }
        // if two in a row
        if(random1 == random2 || random2 == random3){
            cout << "Two of a kind in a row! You win your bet back." << endl;

            int chance = rand() % 4;

            if(chance == 2 && p->getInventory()->hasItem(COMMDEV) == true){
                p->getInventory()->getItem(COMMDEV)->message();
            }
        }
        // nothing matches
        else{
            cout << "You didn't win anything..." << endl;
            p->setMoney(p->getMoney() - bet);
        }

        cout << "Would you like to play again? Enter 1 for yes." << endl;
        getInt(playAgain, 1, 2);
        if(playAgain == 2){
            playing = false;
        }
    }
}

string Slots::slotSymbol(int a){
    switch(a){
        case 0: return "Cherries";
        break;
        case 1: return "777";
        break;
        case 2: return "BAR";
        break;
        case 3: return "7";
        break;
        case 4: return "Double";
        break;
        case 5: return "Jackpot";
        break;
        case 6: return "Diamond";
        break;
        default: return "not valid";
        break;
    }
}