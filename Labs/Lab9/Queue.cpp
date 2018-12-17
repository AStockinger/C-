/******************************************************************************
 ** Program name: Lab 9
 ** Author: Amy Stockinger
 ** Date: 11/20/18
 ** Description: a class that implements std::queue using the push and pop
 ** functions while pushing/popping numbers according to RNG vs user-chosen
 ** percentages, and keeping track of the length and average length of the queue
******************************************************************************/

#include "Queue.hpp"
#include <queue>
using std::cout;
using std::endl;
using std::queue;

Queue::Queue(){
    length = 0;
    avgLength = 0;
}

void Queue::simulation(int rounds, int percentageAdd, int percentageRemove){
    int count = 1;

    while(count <= rounds){
        // generate numbers
        int N = (rand() % 1000) + 1;                // random number that may be added to queue
        int appendingNumber = (rand() % 100) + 1;   // percentage to add a number
        int removingNumber = (rand() % 100) + 1;    // percentage to remove a number

        // print round number 
        cout << "Round " << count << ", N = " << N << endl;

        // compare randomly generated add-num percentage to user-given percentage
        cout << "Random " << appendingNumber;
        if(appendingNumber > percentageAdd){
            cout << "% > " << percentageAdd << "%, no push" << endl;
        }
        else if(appendingNumber <= percentageAdd){
            cout << "% <= " << percentageAdd << "%, Push " << N << endl;
            buffer.push(N);
            length++;
        }

        // compare randomly generated delete-num percentage to user-given percentage
        cout << "Random " << removingNumber;
        if(removingNumber > percentageRemove){
            cout << "% > " << percentageRemove << "%, no pop" << endl;
        }
        else if(removingNumber <= percentageRemove && !buffer.empty()){
            cout << "% <= " << percentageRemove << "%, Pop " << buffer.front() << endl;
            buffer.pop();
            length--;
        }
        else if(buffer.empty()){
            cout << " There is nothing to pop." << endl;
        }

        queue<int> copy = buffer;           // make a copy of the current queue

        cout << "Buffer: ";                 // print queue by popping off values
        while(!copy.empty()){               // from the copy queue
        cout << copy.front() << " ";
        copy.pop();
        }
        cout << endl;

        cout << "Current Length: " << length << endl;

        if(count == 1){                     // base case for average length
            avgLength = buffer.size();
        }

        // print the average length each round and then save it to be used in next round's calculation
        cout << "Average Length: " << static_cast<double>((avgLength * (count - 1) + buffer.size()) / count) << endl;
        avgLength = static_cast<double>((avgLength * (count - 1) + buffer.size()) / count);

        cout << endl;
        count++;
    }
}