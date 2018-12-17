/********************************************************************* 
** Program name: Zoo Tycoon
** Author: Amy Stockinger
** Date: Oct 8, 2018
** Description: Animal implementation, including member vars for
** age, cost of animal, number of babies an animal has at a time,
** food cost, and payoff. the functions include getters and setters,
** as well as a bool for age to have babies
*********************************************************************/

#include "Animal.hpp"

// default animal 
Animal::Animal(){
    age = -1;
}

// get/set age
int Animal::getAge(){
    return age;
}
void Animal::setAge(int a){
    age = a;
}

// get/set cost
double Animal::getCost(){
    return cost;
}
void Animal::setCost(double c){
    cost = c;
}

// get babies
int Animal::getBabies(){
    return numBabies;
}
void Animal::setBabies(int a){
    numBabies = a;
}

// get and set food cost
double Animal::getFoodCost(){
    return foodCost;
}
void Animal::setFoodCost(double f){
    foodCost = f;
}

// get/set payoff
double Animal::getPayoff(){
    return payoff;
}
void Animal::setPayoff(double p){
    payoff = p;
}

// bool for if an animal is old enough to reproduce
bool Animal::canHaveBabies(){
    if(age >= 3){
        return true;
    }
    else
        return false;
}