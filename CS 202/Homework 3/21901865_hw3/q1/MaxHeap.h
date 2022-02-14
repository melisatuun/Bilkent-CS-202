/**
* Title: Heap

* Author: Melis Atun

* ID: 21901865

* Assignment: 3

* Description: MaxHeap.h file

*/

#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
using namespace std;
const int MAX_HEAP = 1000;
class MaxHeap {

public:
    MaxHeap(); //constructor

    bool isEmpty() const;
    void heapDelete(int& rootItem);

    //functions
    void insert(int value);
    int peek();
    int extractMax();
    int size();

protected:
    void heapRebuild(int root);

private:
    int sizeMaxHeap; //size of the heap (the name size cannot be used because of the size function)
    int items[MAX_HEAP];
};

#endif
