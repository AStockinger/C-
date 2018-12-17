/********************************************************************* 
** Program name: Zoo Tycoon
** Author: Amy Stockinger
** Date: Oct 8, 2018
** Description: Animal specification, including member vars for
** age, cost of animal, number of babies an animal has at a time,
** food cost, and payoff. the functions include getters and setters,
** as well as a bool for age to have babies
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

const double BASE_FOOD_COST = 10.0;

class Animal{
    protected:
        // member vars as per directions
        int age;
        double cost;
        int numBabies;
        double foodCost;
        double payoff;
    public:
        // constructor
        Animal();
        // getters and setters for each member variable
        int getAge();
        void setAge(int);
        double getCost();
        void setCost(double);
        int getBabies();
        void setBabies(int);
        double getFoodCost();
        void setFoodCost(double);
        double getPayoff();
        void setPayoff(double);
        // bool that is true if an animal is over 3
        bool canHaveBabies();
};
#endif