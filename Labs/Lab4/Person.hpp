/********************************************************************* 
** Program name: Lab 4
** Author: Amy Stockinger
** Date: 10/13/18
** Description: Person specification file
*********************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
using std::string;

class Person{
    protected:
        string name;
        int age;
    public:
        Person();
        virtual ~Person();
        // generates a random number of hours for a person to work
        virtual void do_work() = 0;
        // returns GPA or rating
        virtual double getInfo() = 0;
        // returns person-specific end of sentence
        virtual string ending() = 0;
        // age getter
        int getAge();
        // name getter
        string getName();
};
#endif