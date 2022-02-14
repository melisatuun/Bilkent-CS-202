/**
* Title: Heap

* Author: Melis Atun

* ID: 21901865

* Assignment: 3

* Description: MedianHeap.h file

*/

#ifndef MEDIANHEAP_H
#define MEDIANHEAP_H
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "MinHeap.h"
#include "MaxHeap.h"
using namespace std;
const int MEDIAN_HEAP = 1000;
class MedianHeap {

public:
    MedianHeap(); //constructor

    //functions
    void insert(int value);
    int findMedian();

private:
    int sizeMedianHeap; //size of the heap (the name size cannot be used because of the size function)
    MinHeap minHeap;
    MaxHeap maxHeap;
};

#endif
