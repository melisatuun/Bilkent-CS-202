/**
* Title: HashTables

* Author: Melis Atun

* ID: 21901865

* Assignment: 4

* Description: main.cpp file

*/

#include <string>
#include <stdio.h>
#include <iostream>
#include "HashTable.h"
using namespace std;

int main() {

    CollisionStrategy collision;

    HashTable h1(11, collision);

    int probes = 0;
    int successful = 0;
    int unsuccessful = 0;

    cout << endl;
    cout << "----------LINEAR PROBING----------" << endl;
    collision = LINEAR;

    h1.insert(20); //9
    h1.insert(30); //8
    h1.insert(2); //2
    h1.insert(13); //3
    h1.insert(25); //4
    h1.insert(24); //5
    h1.insert(10); //10
    h1.insert(9); //0

    h1.display();

    cout << endl;
    cout << "AFTER REMOVAL..." << endl;
    h1.remove(9);
    h1.remove(30);
    h1.remove(10);

    h1. display();

    cout << endl;
    cout << "ANALYZING..." << endl;
    h1.analyze(successful, unsuccessful); 

    HashTable h2(11, collision); 

    cout << endl;
    cout << "----------QUADRATIC PROBING----------" << endl;
    collision = QUADRATIC;

    h2.insert_helper(20); //9
    h2.insert_helper(30); //8
    h2.insert_helper(2);  //2
    h2.insert_helper(13); //3
    h2.insert_helper(25); //4
    h2.insert_helper(24); //6
    h2.insert_helper(10); //10
    h2.insert_helper(9);  //7

    h2.display();

    cout << endl;
    cout << "SEARCHING..." << endl;
    h2.search(13, probes); //random item from the above array to test the search function
    cout << "Search done." << endl;
    cout << "Item is found after " << probes << " probes." << endl;

    cout << endl;
    cout << "ANALYZING..." << endl;
    h2.analyze(successful, unsuccessful);

    HashTable h3(11, collision);

    cout << endl;
    cout << "----------DOUBLE HASHING----------" << endl;
    collision = DOUBLE;

    h3.insert_helper2(58); //3
    h3.insert_helper2(14); //0
    h3.insert_helper2(91); //8

    h3.display();

    cout << endl;
    cout << "ANALYZING..." << endl;
    h3.analyze(successful, unsuccessful); 

    /*
    * QUESTION 2, PART 2 TEST BELOW
    */

    HashTable test(20, collision);

    cout << endl;
    cout << "Operation" << endl;
    cout << "I 1234" << endl;
    test.insert(1234);
    if (test.insert(1234) == true) {
        cout << "Insertion is successful. 1234 inserted." << endl;
    }
    else {
        cout << "Insertion is unsuccessful. 1234 not inserted." << endl;
    }


    cout << endl;
    cout << "Operation" << endl;
    cout << "R 1234" << endl;
    test.remove(1234);
    if (test.remove(1234) == true) {
        cout << "Removal is successful. 1234 removed." << endl;
    }
    else {
        cout << "Removal is unsuccessful. 1234 not removed." << endl;
    }


    cout << endl;
    cout << "Operation" << endl;
    cout << "S 1234" << endl;
    test.search(1234, probes);
    if (test.search(1234, probes) == true) {
        cout << "Search is successful. 1234 found after " << probes << " probes." << endl;
    }
    else {
        cout << "Search is unsuccessful. 1234 not found after " << probes << " probes." << endl;
    }
    cout << endl; 


    return 0;
}
