/********************************************************************* 
** Program name: Lab 4
** Author: Amy Stockinger
** Date: 10/13/18
** Description: Instructor specification file, derived from People
** includes overridden functions to do work, and return rating-related
** information
*********************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "Person.hpp"

class Instructor : public Person{
    private:
        // scale of 0-5
        double rating;
    public:
        Instructor();
        virtual ~Instructor();
        // returns random number of hours of paper grading
        void do_work();
        // returns rating
        double getInfo();
        // returns a string for rating
        string ending();
};
#endif