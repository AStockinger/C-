/********************************************************************* 
** Program name: Fantasy Combat Tournament
** Author: Amy Stockinger
** Date: 11/5/18
** Description: Harry Potter class specification
** includes bool for Harry's second life, along with getter and setter
*********************************************************************/


#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character{
    private:
        // will be true when Harry is on his second life
        bool secondLife;
    public:
        // constructor and destructor
        HarryPotter();
        virtual ~HarryPotter();
        // get and set secondLife
        void setLife(bool);
        bool getLife();
        // override damage to implement Hogwarts
        void damage(int);
        string getName();
};
#endif