/**
* Title: Trees

* Author: Melis Atun

* ID: 21901865

* Assignment: 2

* Description: NgramTree.h file

*/

#ifndef NGRAMTREE_H
#define NGRAMTREE_H
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

//NgramTreeNode class
class NgramTreeNode {

private:
    string data;
    int currentCount;
    NgramTreeNode* leftChild;
    NgramTreeNode* rightChild;

    //helper function
    void getCount(int& count);

    //constructor
    NgramTreeNode(const string Ngram, NgramTreeNode *left, NgramTreeNode *right) : currentCount(1), leftChild(NULL), rightChild(NULL) {
        this->data = Ngram;
        this->leftChild = left;
        this->rightChild = right;
    }

    //friend class - can access private parts
    friend class NgramTree;
};

//NgramTree class
class NgramTree {

friend ostream& operator<<(ostream& out, NgramTree tree);

public:
    NgramTree(); //constructor
   ~NgramTree(); //destructor

    //helper functions
    void destroyTree(NgramTreeNode*& treePtr);
    void print(ostream& out, NgramTreeNode* root);
    void addNgram_helper(string str, NgramTreeNode* root);
    bool isFullTreeHelper(NgramTreeNode* root);
    bool checkCompleteHelper(NgramTreeNode* root, int index, int nodeNumber);

    //NgramTree functions
    void addNgram(string ngram);
    int getTotalNgramCount();
    bool isComplete();
    bool isFull();
    void generateTree(string fileName, int n);

private:
    NgramTreeNode* root;
};

#endif
