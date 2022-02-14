/**
* Title: Heap

* Author: Melis Atun

* ID: 21901865

* Assignment: 3

* Description: main.cpp file

*/

#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"
using namespace std;

int main() {
    int myHeap[] = {8, 1, 13, 56, 25, 32, 88, 90, 2, 61, 62, 100};

    MaxHeap maxHeap = MaxHeap();

    for (int i = 0; i < 12; i++)
        maxHeap.insert(myHeap[i]);

    cout << "Testing max heap..." << endl;
    cout << "Maximum element: " << maxHeap.peek() << endl;

    cout << "Size: " << maxHeap.size() << endl;
    for (int i = 0; i < 12; i++)
        cout << maxHeap.extractMax() << endl;

    MinHeap minHeap = MinHeap();

    for (int i = 0; i < 12; i++)
        minHeap.insert(myHeap[i]);

    cout << "Testing min heap..." << endl;
    cout << "Minimum element: " << minHeap.peek() << endl;

    cout << "Size: " << minHeap.size() << endl;
    for (int i = 0; i < 12; i++)
        cout << minHeap.extractMin() << endl;

    MedianHeap medianHeap = MedianHeap();

    for (int i = 0; i < 12; i++)
        medianHeap.insert(myHeap[i]);

    cout << "Testing median heap..." << endl;
    cout << "Median is: " << medianHeap.findMedian() << endl;
}
