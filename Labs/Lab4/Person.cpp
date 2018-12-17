/********************************************************************* 
** Program name: Lab 4
** Author: Amy Stockinger
** Date: 10/13/18
** Description: Person implementation file
*********************************************************************/

#include "Person.hpp"
#include <stdlib.h>
#include <time.h>

// constructor randomly assigns name and age
Person::Person(){
    string names[] = {"Bilal", "Haya", "Zuhair", "Jamil", "Abdulla", "Christopher", "Joel", 
    "Jacob", "Rene", "Granit", "Saoud", "Thomas", "Sarah", "Justin", "Johnny", "Damien", 
    "Rebecca", "Bella", "Christina", "Tacoma", "Kyle", "Ian", "Shonchalay", "Dustin", "Nelson", 
    "Shirley", "Silvia", "Raymon", "Samuel", "Annette", "Sunghoon", "Cameron", "Dallas", 
    "Kimberly", "Hudson", "Alexander", "Stephen", "Meng", "Ryan", "Eric", "Morgan", "Russel", 
    "Cedric", "Ahmad", "Randal", "Dane", "David", "Anthony", "Lennard", "Glen", "Brandon", 
    "Kevin", "Tristan", "Clayton", "Jordan", "Matthew", "Tomiko", "Guillermo", "John", "Gregory",
    "Geraldo", "Evan", "Thuong", "Dmitri", "Jovaun", "Zachary", "Lukas", "Tajeshwar", "Binta", 
    "Laura", "Xiao", "James", "Chi", "Stuart", "Paul", "Melisa", "Jamie", "Anqi", "Yiqiao", "Austin",
    "Khuong", "Phi", "Peter", "Christian", "Danielle", "Nathan", "Shawn", "Ashleigh", "Milad",
    "Chase", "Jenny", "Israel", "Timothy", "Roham", "Luis", "Tsewei", "Samnang", "Erika", "Amy",
    "Robert", "Chelsea", "Richard", "Ayoub", "Tainhong", "Hyunwook", "Steven", "Jordan", "Michael",
    "Alonso", "Andy", "Tuan", "Randolph", "Frandy", "Pedro", "Harlan", "Nicholas", "Eben", "Elijah", 
    "Kadeem", "Rui", "Ellen", "Livia", "Ji", "Liying", "Charles", "Cherie", "Luyao", "Yuxi", "Chen"};
    int randName = rand() % 129;
    name = names[randName];
    age = (rand() % 20) + 18;
}

Person::~Person(){}

// get age/name
int Person::getAge(){
    return age;
}
string Person::getName(){
    return name;
}