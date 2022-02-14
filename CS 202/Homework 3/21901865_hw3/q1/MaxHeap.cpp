/**
* Title: Heap

* Author: Melis Atun

* ID: 21901865

* Assignment: 3

* Description: MaxHeap.cpp file

*/

#include "MaxHeap.h"
using namespace std;

//constructor
MaxHeap::MaxHeap() : sizeMaxHeap(0) {
}

//isEmpty function
bool MaxHeap::isEmpty() const {
    return (sizeMaxHeap == 0);
}

//heapDelete function
void MaxHeap::heapDelete(int& rootItem) {
    if (isEmpty()) 
        cout << "Heap is empty." << endl;
    else {
        int maximum = items[0];
        items[0] = items[--sizeMaxHeap];
        heapRebuild(0);
    }
}

//inserts integer into heap
void MaxHeap::insert(int value) {
    if (sizeMaxHeap >= MAX_HEAP) 
        cout << "Heap is full." << endl;
    else {
        items[sizeMaxHeap] = value;
        int place = sizeMaxHeap;
        int parent = (place - 1) / 2;
        while ((place > 0) && (items[place] > items[parent])) {
            int temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;
            place = parent;
            parent = (place - 1) / 2;
        }
        sizeMaxHeap++;
    }
}

//returns the value of the max element
int MaxHeap::peek() {
    if (!isEmpty()) {
        int maximum = items[0];
        return maximum;
    }
    else 
        return 0;
}

//retrieves and removes the max element
int MaxHeap::extractMax() {
    if (isEmpty())
        cout << "Heap is empty." << endl;
    int maximum = peek();
    heapDelete(items[0]);
    return maximum;
}

//returns the number of elements in the heap
int MaxHeap::size() {
    if (isEmpty())
        return 0;
    else
        return sizeMaxHeap;
}

//heapRebuild function
void MaxHeap::heapRebuild(int root) {
    int child = 2 * root + 1; //index of root's left child, if any
    if (child < sizeMaxHeap) {
        //root is not a leaf so that it has a left child
        int rightChild = child + 1;
        //if root has right child, find larger child
        if ((rightChild < sizeMaxHeap) && (items[rightChild] > items[child]))
            child = rightChild; //index of larger child
        //if root's item is smaller than larger child, swap values
        if (items[root] < items[child]) {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            //transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}

