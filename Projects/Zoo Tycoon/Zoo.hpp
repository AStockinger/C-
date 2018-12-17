/********************************************************************* 
** Program name: Zoo Tycoon
** Author: Amy Stockinger
** Date: Oct 8, 2018
** Description: Zoo specification
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <fstream>
using std::fstream;

const double PREMIUM_FOOD = 2.0;
const double CHEAP_FOOD = 0.5;

class Zoo{
    private:
        // counters for money, days and animals
        double totalMoney;
        int days;
        int tigers;
        int penguins;
        int turtles;
        // arrays and array sizes
        Tiger* tigerArray;
        int tigerCapacity;
        Penguin* penArray;
        int penCapacity;
        Turtle* turtleArray;
        int turtleCapacity;
        // bools for food type
        bool premiumFood;
        bool cheapFood;
    public:
        // constructors and destructor
        Zoo();
        ~Zoo();
        // add and remove animals from zoo
        void addTiger(int, double);
        void tigerDied();
        void addPenguin(int, double);
        void penguinDied();
        void addTurtle(int, double);
        void turtleDied();
        // manage money
        double getTotalMoney();
        void setTotalMoney(double);
        // random event generation
        void randomEvent();
        // age animals and subtract food costs
        void dayPassed();
        // food preference functions
        void setPremium(bool);
        void setCheap(bool);
        void resetFoodPref();
        // print line from selected file
        void GotoLine(unsigned int);
        // user gameplay menu
        void startGame();
};
#endif