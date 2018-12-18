/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Bar implementation. Mostly dialogue, player must obtain
 ** an item here first to begin the quest line.
******************************************************************************/

#include "Bar.hpp"
#include "StairKey.hpp"
#include "InputVal.hpp"
#include <iostream>

using std::cout;
using std::endl;

Bar::Bar(){
    key = new StairKey();
    hasKey = false;
}

Bar::~Bar(){
    delete key;
}

// narrative where you meet a lady friend and get an item
void Bar::interact(Player* p){
    cout << "You wander over to the bar to get a better look around." << endl;
    cout << "Bartender: 'What are you havin'?'" << endl;
    cout << "'Martini, shaken not stirred,' you say." << endl;

    if(hasKey == false){
        cout << "Just then, you glance up to see a beautiful lady has taken the spot next to you." << endl;
        cout << "'You're a new face around here', she notes. 'Mind if I join you?'" << endl;
        cout << "You smile and decide to probe around for information. She is clearly a regular." << endl;
        cout << endl;

        cout << "'Le Chiffre throws quite the parties, hm?', you say." << endl;
        cout << "'Who doesn't love a good night out with a few hundred thousand dollars?', she muses" << endl;
        cout << "'He makes quite a bit of money here. Not sure it's all legal.'" << endl;
        cout << "'What makes you say that?', you inquire." << endl;
        cout << "'It's just fishy how often he wins. He seeks out the high rollers...'" << endl;
        cout << "'If you get lucky enough, you might get an invite to lose', she adds." << endl;
        cout << "'Is that what all this security is for?', you gesture to the employees walking around." << endl;
        cout << "She flashes a smile, and nods toward the locked door." << endl;
        cout << "'Here', she says, 'Maybe this will help you.'" << endl;

        p->getInventory()->addItem(*key);
        hasKey = true;

        cout << "She hands you a keyring containing an unmarked key." << endl;
        cout << endl;
    }
    else{
        cout << "Nothing else interesting here." << endl;
        cout << endl;
    }
}