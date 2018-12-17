/******************************************************************************
 ** Program name: Lab 8
 ** Author: Amy Stockinger
 ** Date: 11/11/18
 ** Description: search and sort functions, including reading a file into an
 ** array, a simple search, a sort, and a binary search

 ** sources:
 ** for sort: https://www.geeksforgeeks.org/recursive-bubble-sort/
 ** for binary search: https://ai.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
******************************************************************************/

#include "SearchAndSort.hpp"
#include "InputVal.hpp"

using std::cout;
using std::cin;
using std::endl;

// creates an array from int data of a txt file
int readFromFile(string fileName, int* someArray){
    ifstream myFile;
    myFile.open(fileName);

    if(!myFile.is_open()){          // return nothing if file not found
        return 0;
    }

    int i = 0;
    while(!myFile.eof()){           // write to file
        myFile >> someArray[i];
        i++;                        // count the number of entries
    }

    myFile.close();                 // close file

    return i;                       // return array size
}

// performs simple search for each required file
void simpleSearch(int val, string fileName){
    ifstream myFile;
    myFile.open(fileName);
    int num;

    while(!myFile.eof()){
        myFile >> num;              // read nums
        if(num == val){             // print message if found
            cout << fileName << ": target value found" << endl;
            return;
        }
    }
    cout << fileName << ": target value not found" << endl;
    return;
}

// prints output values as well as places them into output files
string sort(string fileName){
    int array[11];                              // make array
    ofstream outputFile;
    string name;
    int size = readFromFile(fileName, array);   // fill array

    bubbleSort(array, size);                    // sort array

    cout << "What would you like the sorted output file name to be? ";
    getline(cin, name);                         // get file name

    outputFile.open(name);

    for(int i = 0; i < size; i++){
        outputFile << array[i] << endl;         // write to file
        cout << array[i] << " ";                // print to screen
    }
    cout << endl;

    outputFile.close();

    return name;                                // return name for use in binary search
}

void bubbleSort(int arr[], int n){ 
    // Base case 
    if (n < 2){
        return;
    }
    // swap elements in array until the largest number is at the highest index
    for (int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }     
    // Largest element is in proper place, so recur for remaining array 
    bubbleSort(arr, n - 1); 
} 

// performs simple search for each required file
void binarySearch(int val, string fileName){
    int array[11];
    bool found = false;
    int mid, min = 0, max = readFromFile(fileName, array) - 1;        // first and last indices

    while(min <= max){
        mid = min + ((max - min) / 2);
        if(array[mid] == val){
            cout << fileName << ": target value found" << endl;
            return;
        }
        else if(array[mid] > val){
            max = mid - 1;
        }
        else if(array[mid] < val){
            min = mid + 1;
        }
    }
    if(!found){
        cout << fileName << ": target value not found" << endl;
        return;
    }
}