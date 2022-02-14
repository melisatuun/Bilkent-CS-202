/**
* Title: Heap

* Author: Melis Atun

* ID: 21901865

* Assignment: 3

* Description: MinHeap.cpp file

*/

#include "MinHeap.h"
#include <string>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
using namespace std;

//constructor
MinHeap::MinHeap() : sizeMinHeap(0) {
}

//isEmpty function
bool MinHeap::isEmpty() const {
    return (sizeMinHeap == 0);
}

//heapDelete function
void MinHeap::heapDelete(int& rootItem) {
    if (isEmpty())
        cout << "Heap is empty." << endl;
    else {
        int maximum = items[0];
        items[0] = items[--sizeMinHeap];
        heapRebuild(0);
    }
}

//inserts integer into heap
void MinHeap::insert(int value) {
    if (sizeMinHeap >= MIN_HEAP)
        cout << "Heap is full." << endl;
    else {
        items[sizeMinHeap] = value;
        int place = sizeMinHeap;
        int parent = (place - 1) / 2;
        while ((place > 0) && (items[parent] > items[place])) {
            int temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;
            place = parent;
            parent = (place - 1) / 2;
        }
        sizeMinHeap++;
    }
}

//returns the value of the max element
int MinHeap::peek() {
    if (!isEmpty()) {
        int minimum = items[0];
        return minimum;
    }
    else
        return 0;
}

//retrieves and removes the max element
int MinHeap::extractMin() {
    if (isEmpty())
        cout << "Heap is empty." << endl;

    int minimum = peek();
    heapDelete(items[0]);
    return minimum;
}

//returns the number of elements in the heap
int MinHeap::size()
{
    if (isEmpty())
        return 0;
    else
        return sizeMinHeap;
}

//heapRebuild function
void MinHeap::heapRebuild(int root) {
    int child = 2 * root + 1; //index of root's left child, if any
    if (child < sizeMinHeap) {
        //root is not a leaf so that it has a left child
        int rightChild = child + 1;
        //if root has right child, find larger child
        if ((rightChild < sizeMinHeap) && (items[child] > items[rightChild]))
            child = rightChild; //index of larger child
        //if root's item is smaller than larger child, swap values
        if (items[root] > items[child]) {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            //transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}
