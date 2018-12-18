/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Game implementation file, manages starting the game and
 ** the main game menu, printing the board, and tracking location
******************************************************************************/

#include "Game.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

Game::Game(){
    int start;

    cout << "What would you like to do?" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Exit" << endl;

    getInt(start, 1, 2);

    if(start == 2){
        exit(0);
    }

    else{
        string playerName;

        cout << "Awesome ASCII art from: https://asciiart.website/index.php" << endl;
        cout << endl;

        cout << "DISCLAIMER: This game contains casino game simulations for entertainment purposes." << endl;
        cout << "It is not affiliated with casinos and does not support gambling." << endl;
        cout << endl;

        cout << "            0000             0000        7777777777777777/========___________" << endl;
        cout << "          00000000         00000000      7777^^^^^^^7777/ || ||   ___________" << endl;
        cout << "         000    000       000    000     777       7777/=========//"           << endl;
        cout << "        000      000     000      000             7777// ((     //"            << endl;
        cout << "       0000      0000   0000      0000           7777//   \\   //"             << endl;
        cout << "       0000      0000   0000      0000          7777//========//"              << endl;
        cout << "       0000      0000   0000      0000         7777"                           << endl;
        cout << "       0000      0000   0000      0000        7777"                            << endl;
        cout << "        000      000     000      000        7777"                             << endl;
        cout << "         000    000       000    000       77777"                              << endl;
        cout << "          00000000         00000000       7777777"                             << endl;
        cout << "            0000             0000        777777777"                            << endl;
        cout << endl;

        // intro blurb
        cout << "                              *****************" << endl;
        cout << "                              ** THE MISSION **" << endl;
        cout << "                              *****************" << endl;
        cout << "******************************************************************************" << endl;
        cout << "* Agent 007, we have received word that Le Chiffre is up to no good again.   *" << endl;
        cout << "* We've gotten you an invitation to his swanky casino party.                 *" << endl;
        cout << "* It will be your job to find a breach in security to allow your teammates.  *" << endl;
        cout << "* to sneak in. Everyone will have to blend in while looking for clues.       *" << endl;
        cout << "* Remember, this is a high-rollers casino, so it is high stakes.             *" << endl;
        cout << "* You have $100,000.00 to begin. Don't lose it all, or the mission is failed!*" << endl;
        cout << "* Also, don't take too long! The fate of the world is at stake.              *" << endl;
        cout << "******************************************************************************" << endl; 
        cout << endl;
        // enter char name
        cout << "What is your name?" << endl;
        cin >> playerName;

        // allocate player and spaces
        player = new Player(playerName);
        roof = new Roof();
        bar = new Bar();
        roulette = new Roulette();
        blackjack = new Blackjack();
        slots = new Slots();
        exclusive = new Exclusive();

        // set spaces
        roof->setDown(bar);
        roof->setRight(slots);
        bar->setUp(roof);
        bar->setRight(blackjack);
        blackjack->setLeft(bar);
        blackjack->setUp(slots);
        blackjack->setRight(roulette);
        slots->setLeft(roof);
        slots->setDown(blackjack);
        slots->setRight(exclusive);
        roulette->setLeft(blackjack);
        roulette->setUp(exclusive);
        exclusive->setDown(roulette);
        exclusive->setRight(slots);

        player->setCurrentSpace(bar);
    }
    startGame();

    return;
}

Game::~Game(){
    delete player;
    delete roof;
    delete bar;
    delete roulette;
    delete blackjack;
    delete slots;
    delete exclusive;
}

void Game::startGame(){
    gamePlay = true;
    int choice = 0;
    int steps = 0;

    cout << "You arrive into a grand casino, and the first thing you notice is a mysterious door by the main bar." << endl;
    cout << "Maybe you should scope out the area first." << endl;

    while(gamePlay == true){
        
        cout << "What would you like to do?" << endl;
        cout << "1. Move up" << endl;
        cout << "2. Move right" << endl;
        cout << "3. Move down" << endl;
        cout << "4. Move left" << endl;
        cout << "5. Stay here" << endl;
        cout << "6. Exit game" << endl;

        getInt(choice, 1, 6);

        // move and interact with space
        switch(choice){
            case 1: 
                if(player->getCurrentSpace()->getUp() != NULL){
                    player->setCurrentSpace(player->getCurrentSpace()->getUp());
                    player->getCurrentSpace()->interact(player);
                }
                else{
                    cout << "You cannot go that way." << endl;
                }
            break;
            case 2: 
                if(player->getCurrentSpace()->getRight() != NULL){
                    player->setCurrentSpace(player->getCurrentSpace()->getRight());
                    player->getCurrentSpace()->interact(player);
                }
                else{
                    cout << "You cannot go that way." << endl;
                }
            break;
            case 3: 
                if(player->getCurrentSpace()->getDown() != NULL){
                    player->setCurrentSpace(player->getCurrentSpace()->getDown());
                    player->getCurrentSpace()->interact(player);
                }
                else{
                    cout << "You cannot go that way." << endl;
                }
            break;
            case 4: 
                if(player->getCurrentSpace()->getLeft() != NULL){
                    player->setCurrentSpace(player->getCurrentSpace()->getLeft());
                    player->getCurrentSpace()->interact(player);
                }
                else{
                    cout << "You cannot go that way." << endl;
                }
            break;
            case 5: player->getCurrentSpace()->interact(player);
            break;
            case 6: exit(0);
            break;
        }

        if(exclusive->gameWon() == true){
            return;
        }

        // show map and total money
        printMap();
        steps++;
        cout << "Your money: " << player->getMoney() << endl;

        // player loses if their money is zero or below
        if(player->getMoney() <= 0){
            cout << "You're out of money. You've failed!" << endl;
            return;
        }
        if(steps > 30){
            cout << "Too late! It seems the party is over..." << endl;
            cout << "You've failed!" << endl;
            return;
        }
        cout << endl;
    }
}

void Game::printMap(){

    // map print
    cout << "*______________________________________*" << endl;
    cout << "|          |              |            |" << endl;
    cout << "|   Door   |     Slots    |    ???     |" << endl;
    cout << "|          |              |            |" << endl;
    cout << "*______________________________________*" << endl;
    cout << "|          |              |            |" << endl;
    cout << "|   Bar    |   Blackjack  |  Roulette  |" << endl;
    cout << "|          |              |            |" << endl;
    cout << "*______________________________________*" << endl;

    // indicate player's current space for reference
    if(player->getCurrentSpace() == bar){
        cout << "You are at the bar." << endl;
    }
    else if(player->getCurrentSpace() == roof){
        cout << "You are at the door to the roof." << endl;
    }
    else if(player->getCurrentSpace() == slots){
        cout << "You are at the slots." << endl;
    }
    else if(player->getCurrentSpace() == blackjack){
        cout << "You are at the blackjack tables." << endl;
    }
    else if(player->getCurrentSpace() == exclusive){
        cout << "You are at ???." << endl;
    }
    else if(player->getCurrentSpace() == roulette){
        cout << "You are at the roulette wheel." << endl;
    }
}