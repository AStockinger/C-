/*************************************************************************** 
** Program name: Lab 2 - letter fequencies in a txt file
** Author: Amy Stockinger
** Date: Sept 28, 2018
** Description: function reads the paragraph string from the input 
** file stream, then counts the letter frequencies of that paragraph, 
** and store the frequencies in the array. Disregards upper/lower 
** case letters.
***************************************************************************/

#include "CountLetters.hpp"
#include "OutputLetters.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

// takes an input file stream variable, and a pointer to an array of integers
void count_letters(ifstream &inputFile, int* charArray){
    string inFileName;
    ofstream outputFile;

    // prompt for input file name
    cout << "Which file would you like to read from?" << endl;
    cin >> inFileName;

    // open input file
    inputFile.open(inFileName.c_str());
    // if it cannot be opened, ask again
    while(!inputFile){
        cout << "That file could not be opened. Try again." << endl;
        cin >> inFileName;
        inputFile.open(inFileName.c_str());
    }

    // perform loop until end of file
    while(!inputFile.eof()){
        // variable to represent a "paragraph" terminated by newline
        string paragraph;
        // reset char array to all 0's
        for(int i = 0; i < 26; i++){
            charArray[i] = 0;
        }
        // get paragraph from file
        getline(inputFile, paragraph);
        // get total paragraph length for use in loop
        int length = paragraph.length();
        // use ASCII letter values to correspond to spots in the char array 
        // a is 97 (z is 122) and A is 65 (Z is 90)
        for(int letter = 97; letter < 123; letter++){
            // loop through string to look for letters
            for(int i = 0; i < length; i++){
                // since A is 65, subtract 97 - 65 = 23 to get the differences between uppers and lowers
                if(paragraph[i] == letter || paragraph[i] == letter - 32){
                    // add to array if it's a hit
                    charArray[letter - 97] += 1;
                }
            }
        }
        // write output for the paragraph
        output_letters(outputFile, charArray);
    }
    // close input file
    inputFile.close();
}