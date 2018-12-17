/********************************************************************* 
** Program name: Lab 4
** Author: Amy Stockinger
** Date: 10/13/18
** Description: University specification file, includes container
** for people and buildings, as well as functions to print information
** about both. Also, setters for additions, and a random person
** generator
*********************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include "Building.hpp"
#include "Instructor.hpp"
#include "Student.hpp"

#include <vector>
#include <string>
using std::string;
using std::vector;

class University{
    private:
        string name;
        // containers for buildings and people pointers
        vector<Building*> buildings;
        vector<Person*> people;
        // number of buildings and people in the university
        int numBuildings, numPeople;
    public:
        University(int, int);
        ~University();
        // add a person
        void setPerson(Person*);
        // returns the people container
        Person* getPeople(int);
        // add a building
        void setBuilding(Building*);
        // returns the building container
        Building* getBuildings(int);
        // returns pointer to random person
        Person* getRandPerson();
        // print requested info functions
        void printBuildingInfo();
        void printPeopleInfo();
};
#endif