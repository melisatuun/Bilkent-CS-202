/**
* Title: HashTables

* Author: Melis Atun

* ID: 21901865

* Assignment: 4

* Description: HashTable.h file

*/

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

enum CollisionStrategy
{
    LINEAR,
    QUADRATIC,
    DOUBLE
};

class HashTable {
    public:

        //functions
        HashTable(const int tableSize, const CollisionStrategy option);
        ~HashTable();
        bool insert(const int item);
        bool remove(const int item);
        bool search(const int item, int& numProbes);
        void display();
        void analyze(int& numSuccProbes, int& numUnsuccProbes);

        //helper functions
        int hashFunction(int m);
        int collisionResolutionLinearProbing(int index);
        int collisionResolutionQuadraticProbing(int index);
        int collisionResolutionDoubleHashing(int index);
        int hash2forDoubleHashing(int key);
        bool insert_helper(const int item);
        bool insert_helper2(const int item);

    private:

        int tableSize;
        int* hashTable;
        CollisionStrategy strategy;
        
};

#endif