/********************************************************************* 
** Program name: Fantasy Combat Tournament
** Author: Amy Stockinger
** Date: 11/5/18 
** Description: Game function implementation
**
*********************************************************************/

#include <iostream>
#include <string>
#include "Game.hpp"
#include "InputVal.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

Game::Game(){
    rounds = 0;
    scoreOne = 0;
    scoreTwo = 0;
    losers = new LoserStack;
    One = new CharacterQueue;
    Two = new CharacterQueue;
    initialize();
}

Game::~Game(){
    delete losers;
    delete One;
    delete Two;
}

// adds character to inputted queue
void Game::selectCharacter(CharacterQueue* a){
    int choice;
    string charName, type;
    Character* c = nullptr;

    // have user pick a fighter
    cout << "Please choose a character for your team:" << endl
    << "1. The Barbarian" << endl
    << "2. The Blue Men" << endl
    << "3. Harry Potter" << endl
    << "4. Medusa" << endl
    << "5. The Vampire" << endl;

    cout << "Enter fighter choice: ";
    getInt(choice, 1, 5);

    cout << "Enter a name for your character: ";
    getline(cin, charName);    

    switch(choice){
        case 1: c = new Barbarian;
                type = "Barbarian";
            break;
        case 2: c = new BlueMen;
                type = "Blue Men";
            break;
        case 3: c = new HarryPotter;
                type = "Harry Potter";
            break;
        case 4: c = new Medusa;
                type = "Medusa";
            break;
        case 5: c = new Vampire;
                type = "Vampire";
            break;
    }
    a->addBack(c, charName, type);
}

// must cycle through queues and have fighters fight while adding losers to the loser stack
void Game::initialize(){
    cout << "How many characters are on Team 1?" << endl;
    getInt(teamOne, 1, 1000);
    for(int i = 0; i < teamOne; i++){
        selectCharacter(One);
    }

    cout << "How many characters are on Team 2?" << endl;
    getInt(teamTwo, 1, 1000);
    for(int i = 0; i < teamTwo; i++){
        selectCharacter(Two);
    }
    
    while(!One->isEmpty() && !Two->isEmpty()){
        fightChars();
    }

    if(scoreOne > scoreTwo){
        cout << "Team 1 wins the Tournament!!" << endl;
        cout << "Team 1 score: " << scoreOne << endl;
        cout << "Team 2 score: " << scoreTwo << endl;
    }

    else if(scoreOne < scoreTwo){
        cout << "Team 2 wins the Tournament!!" << endl;
        cout << "Team 2 score: " << scoreTwo << endl;
        cout << "Team 1 score: " << scoreOne << endl;
    }
    else{
        cout << "This Tournament is a draw!" << endl;
    }

    int viewLosers;
    cout << "Would you like to view the loser pile? Enter 1 for YES and 2 for NO." << endl;
    getInt(viewLosers, 1, 2);

    if(viewLosers == 1){
        losers->printList();
    }
}

// determines round winner
void Game::fightChars(){
    rounds++;

    // print who is fighting this round
    cout << "Round " << rounds << ": " << One->getFront()->name << " the " << One->getFront()->characterType << 
            " vs. " << Two->getFront()->name << " the " << Two->getFront()->characterType << endl;

    while(One->getFront()->character->getStrength() > 0 && Two->getFront()->character->getStrength() > 0){

        One->getFront()->character->damage(Two->getFront()->character->fight(One->getFront()->character));

        // check status if a player "dies"
        if(One->getFront()->character->getStrength() <= 0 && Two->getFront()->character->getStrength() > 0){
            cout << Two->getFront()->name << " the " << Two->getFront()->characterType << " wins!" << endl;
            cout << "Team 2 wins round " << rounds << endl << endl;
            scoreTwo++;
            losers->addHeadNode(One->removeFront());
            Two->getFront()->character->heal();
            Two->moveHeadToBack();                              // move back -- HEAL!
            return;
        }
        else if(One->getFront()->character->getStrength() > 0 && Two->getFront()->character->getStrength() <= 0){
            cout << One->getFront()->name << " the " << One->getFront()->characterType << " wins!" << endl;
            cout << "Team 1 wins round " << rounds << endl << endl;
            scoreOne++;
            losers->addHeadNode(Two->removeFront());
            One->getFront()->character->heal();
            One->moveHeadToBack();
            return;
        }
        else if(One->getFront()->character->getStrength() <= 0 && Two->getFront()->character->getStrength() <= 0){
            cout << rounds << " is a tie round!" << endl << endl;
            losers->addHeadNode(One->removeFront());
            losers->addHeadNode(Two->removeFront());
            return;
        }

        // then fighter B moves
        Two->getFront()->character->damage(One->getFront()->character->fight(Two->getFront()->character));

        // check status again
        if(One->getFront()->character->getStrength() <= 0 && Two->getFront()->character->getStrength() > 0){
            cout << Two->getFront()->name << " the " << Two->getFront()->characterType << " wins!" << endl;
            cout << "Team 2 wins round " << rounds << endl << endl;
            scoreTwo++;
            losers->addHeadNode(One->removeFront());
            Two->getFront()->character->heal();
            Two->moveHeadToBack();                              // move back -- HEAL!
            return;
        }
        else if(One->getFront()->character->getStrength() > 0 && Two->getFront()->character->getStrength() <= 0){
            cout << One->getFront()->name << " the " << One->getFront()->characterType << " wins!" << endl;
            cout << "Team 1 wins round " << rounds << endl << endl;
            scoreOne++;
            losers->addHeadNode(Two->removeFront());
            One->getFront()->character->heal();
            One->moveHeadToBack();
            return;
        }
        else if(One->getFront()->character->getStrength() <= 0 && Two->getFront()->character->getStrength() <= 0){
            cout << rounds << " is a tie round!" << endl << endl;
            losers->addHeadNode(One->removeFront());
            losers->addHeadNode(Two->removeFront());
            return;
        }
    }
}