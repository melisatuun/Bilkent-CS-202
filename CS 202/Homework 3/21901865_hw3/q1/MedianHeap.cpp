/**
* Title: Heap

* Author: Melis Atun

* ID: 21901865

* Assignment: 3

* Description: MedianHeap.cpp file

*/

#include "MedianHeap.h"
using namespace std;

//constructor
MedianHeap::MedianHeap() : sizeMedianHeap(0) {
}

//inserts an element into heap
void MedianHeap::insert(int value) {
    if (value > maxHeap.peek()) 
        minHeap.insert(value);
    else
        maxHeap.insert(value);
    
    if (minHeap.size() > maxHeap.size()) {
        maxHeap.insert(minHeap.extractMin());
    }
    else if (minHeap.size() < maxHeap.size()) {
        minHeap.insert(maxHeap.extractMax());
    }
    sizeMedianHeap++;
}

//returns the value of the median
int MedianHeap::findMedian() {
    if (sizeMedianHeap == 0)
        cout << "Median heap is empty." << endl;

    if (sizeMedianHeap % 2 == 0) 
        return minHeap.peek();
    else 
        return maxHeap.peek();
}