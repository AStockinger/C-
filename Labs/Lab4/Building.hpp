/********************************************************************* 
** Program name: Lab 4
** Author: Amy Stockinger
** Date: 10/13/18
** Description: Building specification file, includes getters and
** a constructor that will initialize to a real OSU building
*********************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>
using std::string;

class Building{
    private:
        string name, address;
        int size;
    public:
        Building(int);
        ~Building();
        // getters for member variables
        string getName();
        int getSize();
        string getAddress();
};
#endif