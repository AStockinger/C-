/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Roof implementation cuts to a fight scene if the player
 ** has not successfully cleared the area, then gives an item
******************************************************************************/

#include "Roof.hpp"
#include "CommDevice.hpp"
#include "StairKey.hpp"
#include <iostream>

using std::cout;
using std::endl;

// constructor sets bool to false and makes a new communication device for the player to pick up
Roof::Roof() : Space(){
    guard = false;
    device = new CommDevice();
}

// delete device that was created
Roof::~Roof(){
    delete device;
}

void Roof::interact(Player* p){
    if(p->getInventory()->hasItem(KEY) == false){  // check if player has roof key
        cout << "It seems the door to the roof is locked." << endl;
        return;
    }

    // cue fight scene if guard hasn't been knocked out already
    if(getGuard() == false){
        int choice;
        bool guardDown = false;

        // each fighter gets 20 health
        int health = 20;
        int guardHealth = 20;

        cout << "You spot a lone guard on the roof, and manage to disarm him before he notices you." << endl;
        cout << "You each have 20 health." << endl;

        while(!guardDown){
            // player makes a choice
            cout << "What do you do now? 1. Attack OR 2. Defend" << endl;
            getInt(choice, 1, 2);

            // guard's choice is random
            int response = rand() % 2;

            // implement fighter choices
            if(response == 0 && choice == 1){
                cout << "The guard blocks your attack. You dealt 2 damage." << endl;
                guardHealth -= 2;
                if(guardHealth <= 0){
                    guardDown = true;
                }
            }
            if(response == 0 && choice == 2){
                cout << "You both took a defensive stance." << endl;
            }
            if(response == 1 && choice == 1){
                cout << "You each throw a few punches, but you're able to hit harder. You take 4 damage and deal 5." << endl;
                guardHealth -= 5;
                health -= 4;
                if(guardHealth <= 0){
                    guardDown = true;
                }
                if(health <= 0){
                    cout << "You blacked out." << endl;
                    return;
                }
            }
            if(response == 1 && choice == 2){
                int dodge = rand() % 2;
                if(dodge == 0){
                    cout << "You successfully evade the guard's attacks." << endl;
                }
                else{
                    cout << "You only partially blocked the attack, and took 2 damage." << endl;
                    health -= 2;
                }
                if(health <= 0){
                    cout << "You blacked out." << endl;
                    return;
                }
            }
        }
        // if player wins, they can pick up a new item
        cout << "You knocked the guard unconscious! Now your friends will be able to join you inside." << endl;
        cout << "Before returning downstairs, you hear a beeping sound and decide to take the guard's communication device." << endl;
        p->getInventory()->addItem(*device);

        setGuard(true);
    }
    // message for player if the scene is cleared
    else{
        cout << "You have already been up here!" << endl;
    }
}

void Roof::setGuard(bool a){
    guard = a;
}
        
bool Roof::getGuard(){
    return guard;
}