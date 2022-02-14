/**
 
*Title: Algorithm Efficiency and Sorting

*Author: Melis Atun

*ID: 21901865

*Section: 1

*Assignment: 1

*Description: main.cpp file

*/

#include "sorting.h"
#include <iostream>
using namespace std;

int main() {

    srand((int)time(NULL));

    int arr1[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int arr2[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int arr3[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};
    int arr4[16] = {7, 3, 6, 12, 13, 4, 1, 9, 15, 0, 11, 14, 2, 8, 10, 5};

    int compCount = 0;
    int moveCount = 0;

    //for insertion sort
    insertionSort(arr1, 16, compCount, moveCount);
    printArray(arr1, 16);

    //for merge sort
    mergeSort(arr2, 0, 15, compCount, moveCount);
    printArray(arr2, 16);

    //for quick sort
    quickSort(arr3, 0, 15, compCount, moveCount);
    printArray(arr3, 16);

    //for radix sort
    radixSort(arr4, 16);
    printArray(arr4, 16);

    performanceAnalysis();

    return 0;
}
