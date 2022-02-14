/**
* Title: HashTables

* Author: Melis Atun

* ID: 21901865

* Assignment: 4

* Description: HashTable.cpp file

*/

#include <string>
#include <stdio.h>
#include <iostream>
#include "HashTable.h"
using namespace std;

//Constructor that initializes the hash table with the given size.
//The collision resolution strategy is given as an option that will be used in the insert, remove, and search operations.
HashTable::HashTable(const int tableSize, const CollisionStrategy option) {
    HashTable::tableSize = tableSize;
    HashTable::hashTable = new int[tableSize];

    for (int i = 0; i < tableSize; i++) {
        hashTable[i] = -1;
    }

    HashTable::strategy = option;
} 

//Destructor that cleans up any dynamic memory used.
HashTable::~HashTable() {
    delete[] hashTable;
}

//Inserts the given item (also used as the key value) into the hash table, and returns true
//if insertion is successful, and false otherwise.
bool HashTable::insert(const int item) {
    int index = hashFunction(item);

    //for linear probing
    if (hashTable[index] == -1) {
        hashTable[index] = item;
        return true;
    }
    else {
        while (hashTable[index] != -1) {
            index = collisionResolutionLinearProbing(index);
            hashTable[index] = item;
            break;
        }
        return true;
    }
}

//for quadratic probing
bool HashTable::insert_helper(const int item) {
    int index = hashFunction(item);

    if (hashTable[index] == -1) {
        hashTable[index] = item;
        return true;
    }
    else {
        while (hashTable[index] != -1) {
            index = collisionResolutionQuadraticProbing(index);
            hashTable[index] = item;
            break;
        }
        return true;
    }
}

//for double hashing
bool HashTable::insert_helper2(const int item) {
    int index = hashFunction(item);

    if (hashTable[index] == -1) {
        hashTable[index] = item;
        return true;
    }
    else {
        while (hashTable[index] != -1) {
            index = collisionResolutionDoubleHashing(index);
            hashTable[index] = item;
            break;
        }
        return true;
    }
}

//Removes the given item from the hash table, and returns true if removal is successful,
//and false otherwise.
bool HashTable::remove(const int item) {
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[i] == item) {
            hashTable[i] = -1;
            return true;
        }
        else 
            return true;
    }
    return false;
}

//Searches the given item in the hash table, and returns true if search is successful (i.e., the item is found), and false otherwise.
//This function also returns the number of probes used during the search for this item.
bool HashTable::search(const int item, int& numProbes) {
    int hash = hashFunction(item);
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[hash] == item) {
            numProbes++;
            return true;
            break;
        }
        else {
            hash = collisionResolutionLinearProbing(hash);
            numProbes++;
        }
    }
    return false;
}

//Displays the contents of the hash table in the following format:
void HashTable::display() {
    for (int i = 0; i < tableSize; i++) {
        cout << i << ": " << hashTable[i] << endl;
    } 
}

//Analyzes the current hash table in terms of the average number of probes for successful and unsuccessful searches,
//and returns these two values in the variables passed by reference.
//For analyzing the performance for successful searches, you can use the item values currently stored in the table for searching.
//For analyzing the performance of unsuccessful searches, you can initiate a search that starts at each array location (index),
//and count the number of probes needed to reach an empty location in the array for each search.
void HashTable::analyze(int& numSuccProbes, int& numUnsuccProbes) {
    /*
    * Random items can be tested here. For example, since 25 is in the example array (which is the first one in the main function),
    * search functions returns true and number of successful probes is calculated. However, if I write int item = 80, 
    * search function returns false because 80 is not present in the example array and number of unsuccessful searches are calculated.
    */

    int item = 25;

    for (int i = 0; i < tableSize; i++) {
        if (search(item, numSuccProbes) == true) {
            numSuccProbes = numSuccProbes / tableSize;
            break;
        }

        else if (search(item, numUnsuccProbes) == false) {
            numUnsuccProbes = numUnsuccProbes / tableSize;
            break;
        }
    }
    cout << "Analysis done." << endl;
    cout << "Successful probes: " << numSuccProbes << endl;
    cout << "Unsuccessful probes: " << numUnsuccProbes << endl;
}

//hash(key) = key mod tableSize
int HashTable::hashFunction(int m) {
    return m % tableSize;
}

//hi(key) = hash(key) + f(i) mod tableSize 
//linear probing
int HashTable::collisionResolutionLinearProbing(int index) {
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[index] != -1) {
            index = (index + 1) % tableSize;
        }
    }
    return index;
}

//hi(key) = hash(key) + f(i^2) mod tableSize
//quadratic probing
int HashTable::collisionResolutionQuadraticProbing(int index) {
    int check;
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[check] != -1) {
            check = 0;
            check = (index + (i * i)) % tableSize;
        }
    } 
    return check;
}

//hash2(key) = reverse(key) is the secondary hash function that reverses the digits of the key (e.g., reverse(1234) = 4321).
int HashTable::hash2forDoubleHashing(int key) {
    int reversed = 0;
    while (key > 0) {
        reversed = reversed * 10 + key % 10;
        key = key / 10;
    }
    return reversed;
}

//f(i) = i hash2(key)
//double hashing
int HashTable::collisionResolutionDoubleHashing(int index) {
    int check;
    int key;
    for (int i = 0; i < tableSize; i++) {
        if (hashTable[check] != - 1) {
            check = 0;
            check = (index + i * hash2forDoubleHashing(key)) % tableSize;
        }
    }
    return check;
}
