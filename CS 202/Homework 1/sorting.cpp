/**

*Title: Algorithm Efficiency and Sorting

*Author: Melis Atun

*ID: 21901865

*Section: 1

*Assignment: 1

*Description: sorting.cpp file

*/

#include "sorting.h"
#include <iostream>
using namespace std;

//swap function
void swap(int &x, int &y) {

    int temp = x;
    x = y;
    y = temp;
}

//print array function
void printArray(int *arr, int size) {

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//insertion sort
void insertionSort(int *arr, const int size, int &compCount, int &moveCount) {

    for (int unsorted = 1; unsorted < size; ++unsorted) {
        int nextItem = arr[unsorted];
        int loc = unsorted;

        for (;(loc > 0) && (arr[loc - 1] > nextItem); --loc) {
            arr[loc] = arr[loc - 1];
            moveCount++;
        }
        arr[loc] = nextItem;
        compCount++;
    }
}

//merge sort
void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount) {

    compCount++;

    if (first < last) {
        moveCount++;
        int mid = (first + last) / 2;

        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid + 1, last, compCount, moveCount);

        merge(arr, first, mid, last, compCount, moveCount); //merge the halves
    }
}

//merge function
void merge(int *arr, int first, int mid, int last, int &compCount, int &moveCount) {

    const int MAX_SIZE = 30000;
    int temp[MAX_SIZE];

    int first1 = first; //beginning of first subarray
    int last1 = mid; //end of first subarray
    int first2 = mid + 1; //beginning of second subarray
    int last2 = last; //end of second subarray
    int index = first1; //next available location in temp

    for (;(first1 <= last1) && (first2 <= last2); ++index) {
        compCount += 3;
        moveCount++;

        if (arr[first1] < arr[first2]) {
            temp[index] = arr[first1];
            ++first1;
        }
        else {
            temp[index] = arr[first2];
            ++first2;
        }
        compCount++;
        moveCount++;
    }

    //finish the first subarray
    for (;(first1 <= last1); ++first1, ++index) {
        temp[index] = arr[first1];
        moveCount++;
        compCount++;
    }

    //finish the second subarray
    for (;(first2 <= last2); ++first2, ++index) {
        temp[index] = arr[first2];
        moveCount++;
        compCount++;
    }

    //copy the result back into the original array 
    for ((index = first); (index <= last); ++index) {
        arr[index] = temp[index];
        moveCount++;
        compCount++;
    }
}

//quick sort
void quickSort(int *arr, int first, int last, int &compCount, int &moveCount) {

    int pivot;

    if (first < last) {
        compCount++;

        partition(arr, first, last, pivot, compCount, moveCount);

        quickSort(arr, first, pivot - 1, compCount, moveCount);
        quickSort(arr, pivot + 1, last, compCount, moveCount);
    }
}

//partition function
void partition(int arr[], int first, int last, int &pivotIndex, int &compCount, 
                int &moveCount) {

    moveCount += 3;
    int pivot = arr[first]; //copy pivot

    int lastS1 = first; //index of the last item
    int firstUnknown = first + 1; //index of the first item
        
    for (;(firstUnknown <= last); ++firstUnknown) {
        compCount += 2;

        if (arr[firstUnknown] < pivot) {
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1]);
        } 
    }
    moveCount += 4;
    swap(arr[first], arr[lastS1]);
    pivotIndex = lastS1;
}

//getting the maximum element of an array
int getMax(int arr[], int n) {

    int max = arr[0];
    
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

//counting sort function
void countingSort(int arr[], int size, int place) {

    const int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; i < max; ++i) {
        count[i] = 0;
    }

    //Calculate the count of elements
    for (int i = 0; i < size; ++i) {
        count[(arr[i] / place) % 10]++;
    }

    //Calculate the cumulative count
    for (int i = 1; i < max; ++i) {
        count[i] += count[i - 1];
    }

    //Placing the elements in ascending order
    for (int i = size - 1; i >= 0; --i) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < size; ++i) {
        arr[i] = output[i];
    }
}

//radix sort
void radixSort(int *arr, const int size) {
    
    int max = getMax(arr, size);

    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(arr, size, place);
    }
}

//creating arrays for performance analysis
void createArrays(int *arr1, int *arr2, int *arr3, int *arr4, int size) {

    for (int i = 0; i < size; ++i) {
        int random = rand() % size + 1;
        arr1[i] = random;
        arr2[i] = random;
        arr3[i] = random;
        arr4[i] = random;
    }
}

//performance analysis function
void performanceAnalysis() {

    //putting the sizes to an array
    int sizes[8] = {2000, 6000, 10000, 14000, 18000, 22000, 26000, 30000};

    int loopNumber = 100;

    srand((int)time(NULL));

    int compCount = 0;
    int moveCount = 0;

    clock_t time = clock();
    double duration;

    //insertion sort
    cout << "-----------------------------------------------------" << endl;
    cout << "Part a – Time Analysis of Insertion Sort" << endl;
    cout << "Array Size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15)
         << "moveCount" << endl;

    for (int i = 0; i < 8; ++i) {

        int *arr1 = new int[sizes[i]];
        int *arr2 = new int[sizes[i]];
        int *arr3 = new int[sizes[i]];
        int *arr4 = new int[sizes[i]];

        createArrays(arr1, arr2, arr3, arr4, sizes[i]);

        compCount = 0;
        moveCount = 0;

        time = clock();

        for (int k = 0; k < 1000; ++k) {
            insertionSort(arr1, sizes[i], compCount, moveCount);
        }

        duration = 1000 * double(clock() - time) / CLOCKS_PER_SEC;

        //running the function many times and getting the average in order to not encounter any 0 ms
        duration /= 1000;
        duration *= 100;

        cout << sizes[i] << setw(15) << duration << " ms" << setw(15) << compCount << setw(15) 
                << moveCount << endl;

        //deallocate memory
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;

    }

    //merge sort
    cout << "-----------------------------------------------------" << endl;
    cout << "Part b – Time Analysis of Merge Sort" << endl;
    cout << "Array Size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15)
            << "moveCount" << endl;

    for (int i = 0; i < 8; ++i) {

        int *arr1 = new int[sizes[i]];
        int *arr2 = new int[sizes[i]];
        int *arr3 = new int[sizes[i]];
        int *arr4 = new int[sizes[i]];

        createArrays(arr1, arr2, arr3, arr4, sizes[i]);

        compCount = 0;
        moveCount = 0;

        time = clock();

        for (int k = 0; k < 1000; ++k) {
            mergeSort(arr1, 0, sizes[i] - 1, compCount, moveCount);
        }

        duration = 1000 * double(clock() - time) / CLOCKS_PER_SEC;

        //running the function many times and getting the average in order to not encounter any 0 ms
        duration /= 1000;
        duration *= 100;

        cout << sizes[i] << setw(15) << duration << " ms" << setw(15) << compCount << setw(15)
                << moveCount << endl;

        //deallocate memory
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;

    }

    //quick sort
    cout << "-----------------------------------------------------" << endl;
    cout << "Part c – Time Analysis of Quick Sort" << endl;
    cout << "Array Size" << setw(15) << "Time Elapsed" << setw(15) << "compCount" << setw(15)
            << "moveCount" << endl;

    for (int i = 0; i < 8; ++i) {

        int *arr1 = new int[sizes[i]];
        int *arr2 = new int[sizes[i]];
        int *arr3 = new int[sizes[i]];
        int *arr4 = new int[sizes[i]];

        createArrays(arr1, arr2, arr3, arr4, sizes[i]);

        compCount = 0;
        moveCount = 0;

        time = clock();

        for (int k = 0; k < 3; ++k) {
            quickSort(arr1, 0, sizes[i] - 1, compCount, moveCount);
        }

        duration = 1000 * double(clock() - time) / CLOCKS_PER_SEC;

        //running the function many times and getting the average in order to not encounter any 0 ms
        duration /= 3;
        duration *= 100;

        cout << sizes[i] << setw(15) << duration << " ms" << setw(15) << compCount << setw(15)
                << moveCount << endl;

        //deallocate memory
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;

        }

    //radix sort
    cout << "-----------------------------------------------------" << endl;
    cout << "Part d – Time Analysis of Radix Sort" << endl;
    cout << "Array Size" << setw(15) << "Time Elapsed" << endl;

    for (int i = 0; i < 8; ++i) {

        int *arr1 = new int[sizes[i]];
        int *arr2 = new int[sizes[i]];
        int *arr3 = new int[sizes[i]];
        int *arr4 = new int[sizes[i]];

        createArrays(arr1, arr2, arr3, arr4, sizes[i]);

        compCount = 0;
        moveCount = 0;

        time = clock();

        for (int k = 0; k < 1000; ++k) {
            radixSort(arr1, sizes[i]);
        }

        duration = 1000 * double(clock() - time) / CLOCKS_PER_SEC;

        //running the function many times and getting the average in order to not encounter any 0 ms
        duration /= 1000;
        duration *= 100;

        cout << sizes[i] << setw(15) << duration << " ms" << endl;

        //dellocate memory
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;

        }
}
