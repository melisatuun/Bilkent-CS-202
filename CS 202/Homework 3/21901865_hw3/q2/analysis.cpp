/**
* Title: AVLTree

* Author: Melis Atun

* ID: 21901865

* Assignment: 3

* Description: analysis.cpp file

*/

#include "analysis.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iomanip>
using namespace std;

//analysis function
void rotationAnalysis() {
    cout << "Array Size" << "            " << "Random" << "              " << "Ascending" << "              " << "Descending" << endl;
    int rotation1;
    int rotation2;
    int rotation3;

    for (int i = 1000; i <= 10000; i+= 1000) {
        rotationAnalysisHelper(i, rotation1, rotation2, rotation3);
        cout << i << endl << "                      " << rotation1 << "                 " << rotation2 << "                   " << rotation3 << endl;
    }
}

//analysis helper function
void rotationAnalysisHelper(int size, int& rotation1, int& rotation2, int& rotation3) {
    AVLTree tree1;
    AVLTree tree2;
    AVLTree tree3;

    //random integers
    for (int i = 0; i < size; i++) {
        int m = rand();
        tree1.insert(m);
    } 
    rotation1 = tree1.getNumberOfRotations();

    //ascending
    for (int i = 0; i < size; i++) {
        tree2.insert(i);
    }
    rotation2 = tree2.getNumberOfRotations();

    //descending
    for (int i = size; i > 0; i--) {
        tree3.insert(i);
    }
    rotation3 = tree3.getNumberOfRotations();
}

