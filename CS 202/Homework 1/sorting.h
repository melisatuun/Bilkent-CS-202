/**

*Title: Algorithm Efficiency and Sorting

*Author: Melis Atun

*ID: 21901865

*Section: 1

*Assignment: 1

*Description: sorting.h file

*/

#ifndef SORTING_H
#define SORTING_H

#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
void radixSort(int *arr, const int size);

void swap(int &x, int &y);
void countingSort(int arr[], int size, int place);
void createArrays(int *arr1, int *arr2, int *arr3, int *arr4, int size);
void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount);
void partition(int arr[], int first, int last, int &pivotIndex, int &compCount, int &moveCount);
int  getMax(int arr[], int n);
void printArray(int *arr, int size);

void performanceAnalysis();

#endif 

