/**
* Title: Trees

* Author: Melis Atun

* ID: 21901865

* Assignment: 2

* Description: hw2.cpp file to test my program

*/

#include "NgramTree.h"
#include <iostream> 
#include <string>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    NgramTree tree;
    string fileName(argv[1]);
    int n = atoi(argv[2]);
    tree.generateTree(fileName, n);
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << "\n";
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
    cout << "\n";
    cout << "Before insertion..." << endl;
    cout << "Total " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    tree.addNgram("samp");
    tree.addNgram("samp");
    tree.addNgram("zinc");
    tree.addNgram("aatt");
    cout << "\n";
    cout << "After insertion..." << endl;
    cout << "Total " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << "\n";
    cout << tree << endl;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;
    cout << "\n";

    return 0;
}
