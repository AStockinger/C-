/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Roulette implementation
******************************************************************************/

#include "Roulette.hpp"
#include "Player.hpp"
#include <iostream>

using std::cout;
using std::endl;

Roulette::Roulette() : Space(){

}

Roulette::~Roulette(){
}

void Roulette::interact(Player* p){
    int choice;
    bool playing = true;

    cout << "You arrive at the Roulette table. Should you try your luck here?" << endl;
    cout << "1. Play, 2. Not now" << endl;
    getInt(choice, 1, 2);

    if(choice == 2){
        return;
    }

    // describe payouts

    while(playing){
        int num = -1, color = 0, betNum = 0, betColor = 0;
        int playAgain;

        cout << "Will you be betting on: 1. a number, 2. a color, 3. both?" << endl;
        getInt(choice, 1, 3);

        if(choice == 1 || choice == 3){
            cout << "Select a number. Enter 0 to bet on 0, and 37 to bet on 00: ";
            getInt(num, 0, 37);
            cout << "How much on " << num << "? "; 
            getInt(betNum, 1000, 5000);
        }
        if(choice == 2 || choice == 3){
            cout << "Select a color by entering the corresponding integer." << endl;
            cout << "Black = 1, Red = 2, Green = 3" << endl;
            getInt(color, 1, 3);
            cout << "How much are you betting on that color?" << endl;
            getInt(betColor, 1000, 5000);
        }

        bet(p, num, betNum, color, betColor);

        cout << "1. Play again or 2. move along?" << endl;
        getInt(playAgain, 1, 2);

        if(playAgain == 2){
            playing = false;
        }
    }
}

void Roulette::bet(Player* p, int num, int betNum, int color, int betColor){
    int luckyNum = rand() % 38;
    cout << "The number is... " << luckyNum << endl;

    // check numbers
    if(luckyNum == num){
        p->setMoney(p->getMoney() + (betNum * 37));
        cout << "Excellent bet! The ball rolled right into the " << num << " pocket. " <<
        "You won $" << betNum * 37 << endl;
    }
    else if(luckyNum != num && num != -1){
        p->setMoney(p->getMoney() - betNum);
        cout << "The ball did not land on " << num << endl;
    }

    // check colors
    // black
    if(luckyNum == 13 || luckyNum == 24 || luckyNum == 15 || luckyNum == 22 || luckyNum == 17 || 
    luckyNum == 20 || luckyNum == 11 || luckyNum == 26 || luckyNum == 28 || luckyNum == 2 || luckyNum == 35 || 
    luckyNum == 4 || luckyNum == 33 || luckyNum == 6 || luckyNum == 31 || luckyNum == 8 || luckyNum == 29 || 
    luckyNum == 10){
        if(color == 1){
            p->setMoney(p->getMoney() + (betColor * 2));
            cout << "Congratulations! The ball landed on a black number." << endl;
        }
        else if(color != 0){
            p->setMoney(p->getMoney() - betColor);
            cout << "Your color didn't come up this spin." << endl;
        }
    }
    // red
    if(luckyNum  == 1 || luckyNum == 36 || luckyNum == 3 || luckyNum == 34 || luckyNum == 25 ||
    luckyNum == 5 || luckyNum == 32 || luckyNum ==  7 || luckyNum == 30|| luckyNum == 9 || luckyNum == 14 || 
    luckyNum == 23 || luckyNum == 16 || luckyNum ==  21 || luckyNum == 18 || luckyNum == 19 || luckyNum == 12 || 
    luckyNum == 27 || luckyNum ==  27){
        if(color == 2){
            p->setMoney(p->getMoney() + (betColor * 2));
            cout << "Congratulations! The ball landed on a red number." << endl;
        }
        else if(color != 0){
            p->setMoney(p->getMoney() - betColor);
            cout << "Your color didn't come up this spin." << endl;
        }
    }
    // green
    if(luckyNum == 0 || luckyNum == 37){
        if(color == 3){
            p->setMoney(p->getMoney() + (betColor * 37));
            cout << "Excellent bet! The ball rolled into a green pocket. " <<
            "You won $" << betColor * 37 << endl;
        }    
        else if(color != 0){
            p->setMoney(p->getMoney() - betColor);
            cout << "Your color didn't come up this spin." << endl;
        }
    }

    // check money
    if(p->getMoney() <= 0){
        cout << "You've lost all of your money!" << endl;
        exit(0);
    }
}