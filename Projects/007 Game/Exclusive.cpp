/******************************************************************************
 ** Program name: Final Project
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: Exclusive Area implementation file
******************************************************************************/

#include "Exclusive.hpp"
#include "ExclusiveInvite.hpp"
#include "InputVal.hpp"
#include <iostream>

using std::cout;
using std::endl;

Exclusive::Exclusive(){
    win = false;
}

Exclusive::~Exclusive(){
}

void Exclusive::interact(Player* p){
    if(p->getInventory()->hasItem(EXCLUINV) == false){
        cout << "A burly man approaches you. 'This area is reserved for exclusive guests,' he barks." << endl;
        cout << "Not wanting to cause a scene too soon, you walk away." << endl;
    }

    else{
        int choice1;

        cout << "You casually flash your invite and stroll in to have a look around." << endl;
        cout << "You spot a small crowd surrounding Le Chiffre and his backgammon board." << endl;
        cout << "Upon closer inspection, it seems he is allowing his invitees to challenge him." << endl;
        cout << endl;
        cout << "You find a spot in the front of the crowrd just in time to see the lastest game." << endl;
        cout << "A grin creeps onto Le Chiffre's face, and he says 'Why don't we make it interesting?'" << endl;
        cout << "He slides a stack of cash onto the table and glances up." << endl;
        cout << "The current opponent waves his hands, and anncounces 'Not with your luck. You Win." << endl;
        cout << "Just as he vacates his chair, you comment, 'I would have taken double myself...'" << endl;
        cout << "Le Chiffre gestures to the chair and offers you to take over the game." << endl;
        cout << endl;
        cout << "You introduce yourself and take a seat." << endl;
        cout << "Le Chiffre tosses his dice to reveal Double Sixes." << endl;
        cout << "The stake is ruppees, do you have the cash?" << endl;

        cout << "You need double sixes. That's a great deal of luck to get out of this." << endl;
        cout << "'Oh, luck? Well then I shall use player's privilege, and use your lucky dice." << endl;
        cout << "You watch te smile melt off Le Chiffre's face as you toss 2 sixes." << endl;
        cout << "'It's all in the wrist', you smirk. 'I prefer cash.'" << endl;
        cout << "'Spend the money quickly', Le Chiffre leans over and grunts." << endl;
        cout << "'It's not really in the wrist, you know', you say." << endl;
        cout << endl;

        cout << "Just as Le Chiffre tries to make a swift exit, he is caught." << endl;

        cout << "*********************************** YOU WIN! **********************************" << endl;
        cout << endl;
        cout << "###############################################################################" << endl;
        cout << "###############################################################################" << endl;
        cout << "###########################################**##################################" << endl;
        cout << "##########################################*####################################" << endl;
        cout << "####################################**#########################################" << endl;
        cout << "######################################***######################################" << endl;
        cout << "########################################*#######**#############################" << endl;
        cout << "################################*#*###*#**#****  **############################" << endl;
        cout << "###############################****#****          *#####**#####################" << endl;
        cout << "##############################****#***             *####**#####################" << endl;
        cout << "##############################** ***              **####*######################" << endl;
        cout << "##############################******              **####*######################" << endl;
        cout << "######*#####**################**** *              **###**#######*##############" << endl;
        cout << "####***###*****###############*** *               *####*####*#** *   *#########" << endl;
        cout << "#######*#** *  *##############***                 *####*###*** *     **########" << endl;
        cout << "######****     *##############****                *####*###**  *      *########" << endl;
        cout << "#####*****      *#############*##*****        *****###**###**         **#######" << endl;
        cout << "####*******     *############**##** ****   *******####*###*#*   *      *#######" << endl;
        cout << "####****#**  **   ###########******# ****  ** #*#***##*###*#*        ***#######" << endl;
        cout << "#####** ***** **  *######*###** ***    **       ** *##*###***##    *#***#######" << endl;
        cout << "#####**  ****##*   *#####*###**         *          *#**##**##*#*  *############" << endl;
        cout << "######**     #*   ** *##**###**                    ##*###* ****   #***#**######" << endl;
        cout << "#####****   **    *** ##***##**         *         *##*####        *    **######" << endl;
        cout << "#######**         *** ### **#***        *         *#**####        *     #######" << endl;
        cout << "######**          **#####  *#***       **         *#**####*       *    *#######" << endl;
        cout << "######*            *###### ******       *        **#*#####*       *    *#######" << endl;
        cout << "#######    #*      *########******     *** **    **#*######*    * #*  *########" << endl;
        cout << "#######*  *        *########*****      **#**    **#**######*     **  **########" << endl;
        cout << "########*  ***    *#*########*****      *       **##*######*  **#*##**#########" << endl;
        cout << "######### *#      *#***######*****              **##**#####**  *******#########" << endl;
        cout << "#########****    *##***#######****             **##**######***  *****##########" << endl;
        cout << "##########*     *##****#######****  **#**********##**######* *     **##########" << endl;
        cout << "###########   **##*****######*#***            ***##*#######** **  **###########" << endl;
        cout << "################## * **##### **#***    * ********##*#*#####**  *###############" << endl;
        cout << "#################******#####   *****************############*** *##############" << endl;
        cout << "#################******####*    ##** *       ***#############******############" << endl;
        cout << "#################****#######     ##***       **####### *#######******##########" << endl;
        cout << "#################*###########     *##**     **#######   *######################" << endl;
        cout << "##############################      *#*******#####*#*   #######################" << endl;
        cout << "###############################       *#############*  *#######################" << endl;
        cout << "################################        *#########*#   *#* ####################" << endl;
        cout << "#################################*      ***##*######   #*   ###################" << endl;
        cout << "###################################    *########**##   #      #################" << endl;
        cout << "####################################    ########***#*  #      *################" << endl;
        cout << "#####################################   ########**##           **##############" << endl;
        cout << "######################################  ########*##*             ##############" << endl;
        cout << "#######*###*########################### *######*#*#*             *#############" << endl;
        cout << "######################################## ######***#*             *#############" << endl;
        cout << "####################**##################*##########*             *#############" << endl;
        cout << "###################################################**            *#############" << endl;
        cout << "####*###########*###**#########################*##***            *#############" << endl;
        cout << "####*##*#####################################****#***           *##############" << endl;
        cout << "#######*##*#################################*  **##**     *    **##############" << endl;
        cout << "##########**################################*  ***#*** ****  ****##############" << endl;

        win = true;
    }
}

bool Exclusive::gameWon(){
    if(win == true){
        return true;
    }
    else{
        return false;
    }
}