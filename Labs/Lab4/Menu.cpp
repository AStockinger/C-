/********************************************************************* 
** Program name: Lab 4
** Author: Amy Stockinger
** Date: 10/13/18
** Description: Menu implementation
** asks users to play or quit
** if play, then it asks for game customization choices
** and starts the simulation for requested options
*********************************************************************/

#include "Menu.hpp"
#include "University.hpp"
#include "Person.hpp"
#include "InputVal.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// display menu options and validate input option
void mainMenu(){
    // variable for user option choice and total options available
	int option;

	// print menu for user with numbered options
	cout << "Please select an option by entering an integer:" << endl <<
		"1. Start University" << endl <<
		"2. Quit" << endl;

	// get user option
	getInt(option, 1, 2);

    if(option == 1){
        customMenu();
    }
    else{
        exit(0);
    }
}

// menu displays project-specific choices with input validation
void customMenu(){
    // user variables for customization and menu choice
    int buildingNum, students, instructors, choice;
    bool playing = true;

    // get numbers to generate University
    cout << "How many buildings does OSU have?" << endl;
    getInt(buildingNum, 1, 35);

    cout << "How many students are at the university?" << endl;
    getInt(students, 2, 10000);

    cout << "How many instructors are at the university?" << endl;
    getInt(instructors, 1, 1000);

    University* OSU = new University(buildingNum, (students + instructors));

    Building* b;
    // add buildings, students and instructors to university
    for(int i = 0; i < buildingNum; i++){
        b = new Building(i);
        OSU->setBuilding(b);
    }

    Person* p;
    for(int i = 0; i < students; i++){
        p = new Student;
        OSU->setPerson(p);
    }
    for(int j = 0; j < instructors; j++){
        p = new Instructor;
        OSU->setPerson(p);
    }

    // game loop
    while(playing){
        cout << "Select an option from the menu" << endl;
        cout << "1. Print Building information" << endl;
        cout << "2. Print People information" << endl;
        cout << "3. Choose a person to do work" << endl;
        cout << "4. Exit Program" << endl;

        getInt(choice, 1, 4);

        switch(choice){
            case 1: OSU->printBuildingInfo();
            break;
            case 2: OSU->printPeopleInfo();
            break;
            case 3: OSU->getRandPerson()->do_work();
            break;
            case 4: delete OSU;
            return;
            break;
        }
    }
}