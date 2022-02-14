/**
* Title: Heap

* Author: Melis Atun

* ID: 21901865

* Assignment: 3

* Description: MinHeap.h file

*/

#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
using namespace std;
const int MIN_HEAP = 1000;
class MinHeap {

public:
    MinHeap(); //constructor

    bool isEmpty() const;
    void heapDelete(int& rootItem);

    //functions
    void insert(int value);
    int peek();
    int extractMin();
    int size();

protected:
    void heapRebuild(int root);

private:
    int sizeMinHeap; //size of the heap (the name size cannot be used because of the size function)
    int items[MIN_HEAP];
};

#endif
