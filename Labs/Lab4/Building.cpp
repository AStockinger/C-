/********************************************************************* 
** Program name: Lab 4
** Author: Amy Stockinger
** Date: 10/13/18
** Description: Building implementation file, includes getters and
** a constructor that will initialize to a real OSU building
*********************************************************************/

#include "Building.hpp"
#include <stdlib.h>
#include <time.h>

// building will be assigned based on corresponding index for member variables
Building::Building(int random){

    string buildings[] = {"Adams Hall", "Aero Engineering Lab", "Agricultural & Life Sciences Building", 
    "Apiary Building", "Austin Hall", "Ballard Extension Hall", "Batcheller Hall", "Bates Hall", 
    "Beth Ray Center for Academic Support", "Bexell Hall", "Bloss Hall", "Burt Hall", "Cascade Hall", 
    "CH2M Hill Alumni Center", "Clark Laboratory", "Community Hall", "Cordley Hell", "Covell Hall", 
    "Crop Science Building", "Dearborn Hall", "Dixon Recreation Center", "Dryden Hall", "East Greenhouse",
    "Energy Center", "Fairbanks Hall", "Gilbert Hall", "Gilkey Hall", "Gill Coliseum", "Gilmore Hall", 
    "Gladys Valley Gymnastics Center", "Gleeson Hall", "Goss Stadium", "Graf Hall", "Hallie E. Ford Center for Healthy Children & Families",
    "Hattie Redmond Women and Gender Center"};
    int sqft[] = {11168, 3637, 185629, 2996, 107613, 45250, 19953, 16134, 34211, 58621, 84031, 75332,
    33765, 45663, 7446, 25806, 235914, 35760, 57638, 66692, 173776, 22525, 31247, 21575, 37286, 85532,
    22263, 177446, 16683, 18702, 36176, 50732, 38221, 27262, 3394};
    string addresses[] = {"606 SW 15th St", "852 SW 30th St", " 2750 SW Campus Way", "844 SW 35th St", 
    "2751 SW Jefferson Way", "2591 SW Campus Way", "1791 SW Campus Way", "110 SW 26th St", "671 SW 26th St", 
    "2251 SW Campus Way", "2001 SW Western Blvd", "2651 SW Orchard Ave", "601 SW 17th St", "725 SW 26th St", 
    "3260 SW Campus Way", "1650 SW Pioneer Pl", "2701 SW Campus Way", "1691 SW Campus Way", "3050 Campus Way",
    "1891 SW Campus Way", "425 SW 26th St", "450 SW 30th St", "2801 SW Campus Way", "3452 Jefferson Way", 
    "220 SW 26th St", "2100 SW Monrow Ave", "122 SW Waldo Pl", "660 SW 26th St", "124 SW 26th St", 
    "1701 SW Jefferson Ave", "2115 SW Campus Way", "430 SW Langton Pl", "1680 SW Monroe Ave", "2631 SW Campus Way",
    "1700 SW Pioneer Pl"};

    if(random < 0 || random > 35){
        random = rand() % 35;
    }
    name = buildings[random];
    size = sqft[random];
    address = addresses[random];
}

Building::~Building(){}

// getters for member variables
string Building::getName(){
    return name;
}
int Building::getSize(){
    return size;
}    
string Building::getAddress(){
    return address;
}