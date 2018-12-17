/********************************************************************* 
** Program name: Lab 4
** Author: Amy Stockinger
** Date: 10/13/18
** Description: Student specification file, derived from People
** includes overridden functions to do work, and return GPA-related
** information
*********************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

class Student : public Person{
    private:
        // scale of 0-4
        double GPA;
    public:
        Student();
        virtual ~Student();
        // returns random number of hours of homework
        void do_work();
        // returns GPA
        double getInfo();
        // returns a string for GPA
        string ending();
};
#endif