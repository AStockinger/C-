/********************************************************************* 
** Program name: Lab 4
** Author: Amy Stockinger
** Date: 10/13/18
** Description: University implementation file, includes container
** for people and buildings, as well as functions to print information
** about both. Also, setters for additions, and a random person
** generator
*********************************************************************/

#include "University.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setprecision;

University::University(int m, int n){
    name = "Oregon State University";
    numPeople = 0;
    numBuildings = 0;
}

University::~University(){
    for(int i = 0; i < numPeople; i++){
        delete people[i];
    }
    for(int i = 0; i < numBuildings; i++){
        delete buildings[i];
    }
}

// add a person
void University::setPerson(Person* a){
    people.push_back(a);
    numPeople++;
}
// get people vector
Person* University::getPeople(int i){
    return people[i];
}
// add a building
void University::setBuilding(Building* b){
    buildings.push_back(b);
    numBuildings++;
}
// get building vector
Building* University::getBuildings(int i){
    return buildings[i];
}
// return random person pointer
Person* University::getRandPerson(){
    int random = rand() % numPeople;
    return people[random];
}
// print building info for all buildings
void University::printBuildingInfo(){
    for(int i = 0; i < numBuildings; i++){
        cout << buildings[i]->getName() << " is " << buildings[i]->getSize() << "sqft, and is located at " <<
        buildings[i]->getAddress() << " in Corvallis, OR." << endl;
    }
    cout << endl;
}
// print info for all people
void University::printPeopleInfo(){
    for(int i = 0; i < numPeople; i++){
        cout << people[i]->getName() << " is " << people[i]->getAge() << " years old, and has a " << setprecision(2) <<
        people[i]->getInfo() << people[i]->ending() << endl;
    }
    cout << endl;
}