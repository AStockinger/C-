/*************************************************************************** 
** Program name: Lab 2
** Author: Amy Stockinger
** Date: Sept 28, 2018
** Description: asks user for the filename the user would like to output to, 
** then outputs the frequencies of letters to the output file in the format 
** specified above
***************************************************************************/

#include "OutputLetters.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;

void output_letters(ofstream &outputFile, int* charArray){
    // file name variable for user's output
    string outFileName;
    
    // prompt for output file name
    cout << "What would you like the name of the output file to be?" << endl;
    cin >> outFileName;

    // write to file
    outputFile.open(outFileName.c_str());

    // fill array with lower case chars a-z (97-122)
    char asciiArray[26];
    int range = 97;
    for(int i = 0; i < 26; i++){
        asciiArray[i] = range;
        // write to file
        outputFile << asciiArray[i] << ": ";
        outputFile << charArray[i] << "\n";
        range++;
    }
    // close file
    outputFile.close();
}