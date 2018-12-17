/********************************************************************* 
** Program name: Zoo Tycoon
** Author: Amy Stockinger
** Date: Oct 8, 2018
** Description: Zoo implementation
*********************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <limits>
#include <iomanip>
#include "Zoo.hpp"
#include "InputVal.hpp"

using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::fixed;
using std::setprecision;

// constructor with start money argument
Zoo::Zoo(){
    totalMoney = 100000;
    tigers = 0;
    penguins = 0;
    turtles = 0;
    days = 0;

    tigerCapacity = 10;
    penCapacity = 10;
    turtleCapacity = 10;

    tigerArray = new Tiger[tigerCapacity];
    penArray = new Penguin[penCapacity];
    turtleArray = new Turtle[turtleCapacity];

}

// prevent memory leaks by deleting all new objects
Zoo::~Zoo(){
    delete[] tigerArray;
    delete[] penArray;
    delete[] turtleArray;
}

// adding a tiger will increase the array if need be, and deduct cost from the zoo
void Zoo::addTiger(int age, double cost){
    if(tigers == tigerCapacity){
        Tiger* upgradeArr = new Tiger[2 * tigerCapacity];
        for(int i = 0; i < tigerCapacity; i++){
            upgradeArr[i] = tigerArray[i];
        }
        delete[] tigerArray;
        tigerArray = upgradeArr;
        tigerCapacity *= 2;
        upgradeArr = NULL;
    }
    tigerArray[tigers].setAge(age);
    tigerArray[tigers].setCost(cost);
    tigerArray[tigers].setFoodCost(BASE_FOOD_COST * TIGER_FOOD_COST_MULT);
    tigerArray[tigers].setPayoff(TIGER_COST * TIGER_PAYOFF_MULT);
    tigerArray[tigers].setBabies(1);
    tigers++;
    setTotalMoney(totalMoney - cost);
}
// random tiger dies
void Zoo::tigerDied(){
    if(tigers == 0)
        tigers = 0;
    else{
        int randTiger = rand() % tigers;
        tigerArray[randTiger].setAge(-1);
        tigers--;
    }
}
// adding a penguin will increase the array if need be, and deduct cost from the zoo
void Zoo::addPenguin(int age, double cost){
    if(penguins == penCapacity){
        Penguin* upgradeArr = new Penguin[2 * penCapacity];
        for(int i = 0; i < penCapacity; i++){
            upgradeArr[i] = penArray[i];
        }
        delete[] penArray;
        penArray = upgradeArr;
        penCapacity *= 2;
        upgradeArr = NULL;
    }
    penArray[penguins].setAge(age);
    penArray[penguins].setCost(cost);
    penArray[penguins].setFoodCost(BASE_FOOD_COST * PEN_FOOD_COST_MULT);
    penArray[penguins].setPayoff(PENGUIN_COST * PENGUIN_PAYOFF_MULT);
    penArray[penguins].setBabies(5);
    penguins++;
    setTotalMoney(totalMoney - cost);
}
// random penguin dies
void Zoo::penguinDied(){
    if(penguins == 0)
        penguins = 0;
    else{
        int randPen = rand() % penguins;
        penArray[randPen].setAge(-1);
        penguins--;
    }
}
// adding a turtle will increase the array if need be, and deduct cost from the zoo
void Zoo::addTurtle(int age, double cost){
    if(turtles == turtleCapacity){
        Turtle* upgradeArr = new Turtle[2 * turtleCapacity];
        for(int i = 0; i < turtleCapacity; i++){
            upgradeArr[i] = turtleArray[i];
        }
        delete[] turtleArray;
        turtleArray = upgradeArr;
        turtleCapacity *= 2;
        upgradeArr = NULL;
    }
    turtleArray[turtles].setAge(age);
    turtleArray[turtles].setCost(cost);
    turtleArray[turtles].setFoodCost(BASE_FOOD_COST * TURTLE_FOOD_COST_MULT);
    turtleArray[turtles].setPayoff(TURTLE_COST * TURTLE_PAYOFF_MULT);
    turtleArray[turtles].setBabies(10);
    turtles++;
    setTotalMoney(totalMoney - cost);
}
// random turtle dies
void Zoo::turtleDied(){
    if(turtles == 0)
        turtles = 0;
    else{
        int randTurtle = rand() % turtles;
        turtleArray[randTurtle].setAge(-1);
    }
}

// get and set total money
double Zoo::getTotalMoney(){
    return totalMoney;
}
void Zoo::setTotalMoney(double x){
    totalMoney = x;
}

// random event function    
void Zoo::randomEvent(){
    // get a random number from 0 - 3
    int randIndex;

    // double the chance of illness if cheap food
    if(cheapFood == true){
        randIndex = rand() % 5;
    }
    else{
        randIndex = rand() % 4;
    }

    // halve the chance of illness if premium food
    if(premiumFood == true && randIndex == 3){
        int sickOrNot = rand() % 2;
        if(sickOrNot == 1){
            randIndex = 5;
            // read line from file
            GotoLine(1);
            return;
        }
        else{
            randIndex = 3;
        }
    }

    // nothing happens
    if(randIndex == 0){
        GotoLine(2);
    }

    // tiger bonus
    else if(randIndex == 1){
        setTotalMoney(totalMoney + (500.0 * tigers));
        // read from file
        GotoLine(3);
    }

    // animal birth
    else if(randIndex == 2){
        // pick another number  0 - 2
        int randomIndex2 = rand() % 3;

        // check available mature animals
        bool tigerBabies = false, penguinBabies = false, turtleBabies = false;
        for(int i = 0; i < tigerCapacity; i++){
            if(tigerArray[i].canHaveBabies() == true){
                tigerBabies = true;
            }
        }
        for(int i = 0; i < penCapacity; i++){
            if(penArray[i].canHaveBabies() == true){
                penguinBabies = true;
            }
        }
        for(int i = 0; i < turtleCapacity; i++){
            if(turtleArray[i].canHaveBabies() == true){
                turtleBabies = true;
            }
        }

        // have babies   
        if(randomIndex2 == 0){
            if(tigerBabies == true){
                addTiger(0, 0);
                GotoLine(4);
            }
            else if(penguinBabies == true){
                for(int i = 0; i < 5; i++){
                    addPenguin(0, 0);
                }   
                GotoLine(5);
            }
            else if(turtleBabies == true){
                for(int i = 0; i < 10; i++){
                    addTurtle(0, 0);
                }
                GotoLine(6);
            }
            else{
                // no animals old enough to have babies
                GotoLine(7);
            }
        }
        else if(randomIndex2 == 1){
            if(penguinBabies == true){
                for(int i = 0; i < 5; i++){
                    addPenguin(0, 0);
                }   
                GotoLine(5);
            }
            else if(turtleBabies == true){
                for(int i = 0; i < 10; i++){
                    addTurtle(0, 0);
                }
                GotoLine(6);
            }
            else if(tigerBabies == true){
                addTiger(0, 0);
                GotoLine(4);
            }
            else{
                // no animals old enough to have babies
                GotoLine(7);
            }
        }
        else if(randomIndex2 == 2){
            if(turtleBabies == true){
                for(int i = 0; i < 10; i++){
                    addTurtle(0, 0);
                }
                GotoLine(6);
            }
            else if(tigerBabies == true){
                addTiger(0, 0);
                GotoLine(4);
            }
            else if(penguinBabies == true){
                for(int i = 0; i < 5; i++){
                    addPenguin(0, 0);
                }   
                GotoLine(5);
            }
            else{
                // no animals old enough to have babies
                GotoLine(7);
            }
        }
    }

    // animal death
    else if(randIndex == 3 || randIndex == 4){
        // pick another number  0 - 2
        int rand2 = rand() % 3;

        // check available mature animals
        bool tigerExist = false, penguinExist = false, turtleExist = false;
        if(tigers > 0)
            tigerExist = true;
        if(penguins > 0)
            penguinExist = true;
        if(turtles > 0)
            turtleExist = true;
        
        // make sure corresponding animal type exists so one can be removed
        switch(rand2){
            case 0: 
                // tiger dies of illness, if there is one
                if(tigerExist == true){
                    tigerDied();
                    GotoLine(8);
                }
                else{
                    GotoLine(9);
                }
            break;
            case 1: 
                // penguin dies of illness, if there is one
                if(penguinExist == true){
                    penguinDied();
                    GotoLine(10);
                }
                else{
                    GotoLine(11);
                }
            break;
            case 2: 
                // turtle dies of illness, if there is one
                if(turtleExist == true){
                    turtleDied();
                    GotoLine(12);
                }
                else{
                    GotoLine(13);
                }
            break;
        }
    }
    cout << endl;
}

// function for what must happen in a day, to be called after each 'turn'
void Zoo::dayPassed(){
    days++;

    double tigerFeed = 0.0, penFeed = 0.0, turtleFeed = 0.0;
    double tigerPay = 0.0, penPay = 0.0, turtlePay = 0.0;

    // AGE + FEED ANIMALS
    for(int i = 0; i < tigerCapacity; i++){
        if(tigerArray[i].getAge() >= 0){
            // age tigers
            tigerArray[i].setAge(tigerArray[i].getAge() + 1);
            // manage food settings/cost
            if(premiumFood == true){
                setTotalMoney(totalMoney - (tigerArray[i].getFoodCost() * PREMIUM_FOOD));
                tigerFeed += tigerArray[i].getFoodCost() * PREMIUM_FOOD;
            }
            else if(cheapFood == true){
                setTotalMoney(totalMoney - (tigerArray[i].getFoodCost() * CHEAP_FOOD));
                tigerFeed += tigerArray[i].getFoodCost() * CHEAP_FOOD;
            }
            else{
                setTotalMoney(totalMoney - tigerArray[i].getFoodCost());
                tigerFeed += tigerArray[i].getFoodCost();
            }
        }
    }
    for(int i = 0; i < penCapacity; i++){
        if(penArray[i].getAge() >= 0){
            penArray[i].setAge(penArray[i].getAge() + 1);
            if(premiumFood == true){
                setTotalMoney(totalMoney - (penArray[i].getFoodCost() * PREMIUM_FOOD));
                penFeed += penArray[i].getFoodCost() * PREMIUM_FOOD;
            }
            else if(cheapFood == true){
                setTotalMoney(totalMoney - (penArray[i].getFoodCost() * CHEAP_FOOD));
                penFeed += penArray[i].getFoodCost() * CHEAP_FOOD;
            }
            else{
                setTotalMoney(totalMoney - penArray[i].getFoodCost());
                penFeed += penArray[i].getFoodCost();
            }
        }
    }
    for(int i = 0; i < turtleCapacity; i++){
        if(turtleArray[i].getAge() >= 0){
            turtleArray[i].setAge(turtleArray[i].getAge() + 1);
            if(premiumFood == true){
                setTotalMoney(totalMoney - (turtleArray[i].getFoodCost() * PREMIUM_FOOD));
                turtleFeed += turtleArray[i].getFoodCost() * PREMIUM_FOOD;
            }
            else if(cheapFood == true){
                setTotalMoney(totalMoney - (turtleArray[i].getFoodCost() * CHEAP_FOOD));
                turtleFeed += turtleArray[i].getFoodCost() * CHEAP_FOOD;
            }
            else{
                setTotalMoney(totalMoney - turtleArray[i].getFoodCost());
                turtleFeed += turtleArray[i].getFoodCost();
            }
        }
    }  

    // animal feeding cost blurb
    cout << "You have " << tigers << " tigers. That will be $" << tigerFeed << " to feed them today." << endl;
    cout << "You have " << penguins << " penguins. That will be $" << penFeed << " to feed them today." << endl;
    cout << "You have " << turtles << " turtles. That will be $" << turtleFeed << " to feed them today." << endl;
    cout << endl;

    // RANDOM EVENT
    randomEvent();

    cout << endl;

    // PAYOFF
    for(int i = 0; i < tigerCapacity; i++){
        if(tigerArray[i].getAge() >= 0){
            setTotalMoney(totalMoney += tigerArray[i].getPayoff());
            tigerPay += tigerArray[i].getPayoff();
        }
    }
    for(int i = 0; i < penCapacity; i++){
        if(penArray[i].getAge() >= 0){
            setTotalMoney(totalMoney += penArray[i].getPayoff());
            penPay += penArray[i].getPayoff();
        }
    }
    for(int i = 0; i < turtleCapacity; i++){
        if(turtleArray[i].getAge() >= 0){
            setTotalMoney(totalMoney += turtleArray[i].getPayoff());
            turtlePay += turtleArray[i].getPayoff();
        }
    }


    // animal revenue blurb
    cout << "You have " << tigers << " tigers. You made $"  << tigerPay << " today." << endl;
    cout << "You have " << penguins << " penguins. You made $" << penPay << " today." << endl;
    cout << "You have " << turtles << " turtles. You made $" << turtlePay << " today." << endl;
    
    cout << endl;
}

// manage and reset food preferences
void Zoo::setPremium(bool a){
    premiumFood = a;
}     
void Zoo::setCheap(bool a){
    cheapFood = a;
}
void Zoo::resetFoodPref(){
    premiumFood = false;
    cheapFood = false;
}

// read line from file
void Zoo::GotoLine(unsigned int num){
    fstream inputFile;
    inputFile.open("randEvents.txt");
    string s = "";

    for(unsigned int i = 1; i < num + 1; i++){
        getline(inputFile, s);
        if(i == num){
            cout << s;
        }
    }
    inputFile.close();
}

void Zoo::startGame(){
    int number, choice, food;
    bool gamePlay = true;

    cout << fixed << setprecision(2);

    cout << "Congratulations! You now have a zoo. You are given $100,000.00 to start." << endl;

    cout << "You must start off your zoo with at least one type of each animal, but no more than two of each." << endl;
    cout << "How many tigers would you like to purchase?" << endl;
    getInt(number, 1, 2);
    for(int i = 0; i < number; i++){
        addTiger(1, TIGER_COST);
    }

    cout << "How many penguins would you like to purchase?" << endl;
    getInt(number, 1, 2);
    for(int i = 0; i < number; i++){
        addPenguin(1, PENGUIN_COST);
    }
    
    cout << "How many turtles would you like to purchase?" << endl;
    getInt(number, 1, 2);
    for(int i = 0; i < number; i++){
        addTurtle(1, TURTLE_COST);
    }

    cout << endl;

    while(gamePlay){
        cout << "Would you like to feed your animals cheap, generic, or premium food today?" << endl;
        cout << "Cheap food is half the cost of generic, while premium is twice the cost of generic." << endl;
        cout << "Select: 1. Cheap    2. Generic    3. Premium" << endl;
        getInt(food, 1, 3);

        if(food == 3){
            setPremium(true);
            setCheap(false);
        }
        else if(food == 1){
            setCheap(true);
            setPremium(false);
        }

        cout << endl;

        // age and feed animals at start of day
        dayPassed();
        resetFoodPref();

        cout << endl;

        // offer menu choice for day, includes checking on money in case player is running low
        // and cannot afford to purchase animals
        cout << "What would you like to do next? Please select a choice below by entering" <<
        " the corresponding integer value." << endl;
        cout << "1. Purchase adult tiger" << endl;
        cout << "2. Purchase adult penguin" << endl;
        cout << "3. Purchase adult turtle" << endl;
        cout << "4. Check current bank status" << endl;
        cout << "5. Exit program" << endl;
    
        getInt(choice, 1, 5);

        cout << endl;

        // excute choice and implement random event at end of day
        switch (choice){
            case 1: 
                if(getTotalMoney() > TIGER_COST){
                    addTiger(3, TIGER_COST);
                    cout << "You have purchased one adult tiger." << endl;
                }
                else{
                    cout << "You cannot afford a tiger." << endl;
                }
                if(getTotalMoney() <= 0){
                    cout << "You are out of money! You lost." << endl;
                    gamePlay = false;
                    return;
                }
                break;
            case 2:
                if(getTotalMoney() > PENGUIN_COST){
                    addPenguin(3, PENGUIN_COST);
                    cout << "You have purchsed one adult penguin." << endl;
                }
                else{
                    cout << "You cannot afford a penguin." << endl;
                }
                if(getTotalMoney() <= 0){
                    cout << "You are out of money! You lost." << endl;
                    gamePlay = false;
                    return;
                }
                break;
            case 3:
                if(getTotalMoney() > TURTLE_COST){
                    addTurtle(3, TURTLE_COST);
                    cout << "You have purchased one adult turtle." << endl;
                }
                else{
                    cout << "You cannot afford a turtle." << endl;
                }
                if(getTotalMoney() <= 0){
                    cout << "You are out of money! You lost." << endl;
                    gamePlay = false;
                    return;
                }
                break;
            case 4: cout << "Your total is $" << getTotalMoney() << endl;
                if(getTotalMoney() <= 0){
                    cout << "You are out of money! You lost." << endl;
                    gamePlay = false;
                    return;
                }
                break;
            case 5: gamePlay = false; 
                return;
                break;
        }
        cout << endl;
    }
}