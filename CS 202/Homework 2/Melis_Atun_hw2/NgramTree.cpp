/**
* Title: Trees

* Author: Melis Atun

* ID: 21901865

* Assignment: 2

* Description: NgramTree.cpp file

*/

#include "NgramTree.h"
#include <string>
#include <cstring>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream> //this is for reading the txt file
using namespace std;

//constructor
NgramTree::NgramTree() : root(NULL) {
}

//destroy tree function
void NgramTree::destroyTree(NgramTreeNode*& treePtr) {
    if (treePtr != NULL) {
        destroyTree(treePtr->leftChild);
        destroyTree(treePtr->rightChild);
    }
}

//destructor
NgramTree::~NgramTree() {
    destroyTree(root);
}

//helper function for adding Ngrams
void NgramTree::addNgram_helper(string str, NgramTreeNode* root) {
    for (NgramTreeNode* treePtr = root; treePtr != NULL;) {
        //string is already there, increment the count
        if (str == (treePtr->data)) {
            treePtr->currentCount++;
            break;
        }
        //inserting to the left (string was not already there)
        else if (str < (treePtr->data)) {
            if ((treePtr->leftChild) == NULL) { //there is no left child, insert there
                treePtr->leftChild = new NgramTreeNode(str, NULL, NULL);
                break;
            }
            else {
                treePtr = treePtr->leftChild; //move on to find the point of insertion
            }
        }
        //inserting to the right (string was not already there)
        else {
            if ((treePtr->rightChild) == NULL) { //there is no right child, insert there
                treePtr->rightChild = new NgramTreeNode(str, NULL, NULL);
                break;
            }
            else {
                treePtr = treePtr->rightChild; //move on to find the point of insertion
            }
        }
    }
}

//adds the specified n-gram in the BST if not already there; otherwise, it simply increments its count
//adding the nodes in alphabetical order
void NgramTree::addNgram(string ngram) {
    //if tree is empty
    if (root == NULL) {
        root = new NgramTreeNode(ngram, NULL, NULL);
    }

    //tree is not empty, call helper function
    else {
        addNgram_helper(ngram, root);
    }
}

//print helper function
void NgramTree::print(ostream& out, NgramTreeNode* root) {
    if (root != NULL) {
        print(out, root->leftChild);
        cout << root->data << " appears " << root->currentCount << " time(s)" << endl;
        print(out, root->rightChild);
    }
}

//operator overloading
ostream& operator<<(ostream& out, NgramTree tree) {
    tree.print(out, tree.root);
    return out;
}

//reads the input text and generates a BST of n-grams
//in this function, all of the n-grams are detected in the input text and added to the tree by using the addNgram function
void NgramTree::generateTree(string fileName, int n) {
    string m;
    ifstream myFile;
    myFile.open(fileName.c_str(), fstream::in);

    if (myFile.is_open()) {
        while(myFile >> m) {
            if (m.length() >= n) {
                for (int i = 0; i <= m.length() - n; ++i) {
                    addNgram(m.substr(i, n));
                }
            }
        }
        myFile.close();
    }
    else {
        cout << "File cannot be opened." << endl;
    }
}

//helper function
void NgramTreeNode::getCount(int& count) {
    if (this->leftChild != NULL) {
        count++;
        leftChild->getCount(count);
    }
    
    if (this->rightChild != NULL) {
        count++;
        rightChild->getCount(count);
    }
}

//recursively computes and returns the total number of n-grams currently stored in the tree
int NgramTree::getTotalNgramCount() {
    int count = 1;
    NgramTreeNode* treePtr = root;

    if (root == NULL) {
        return 0;
    }
    else {
        treePtr->getCount(count);
    }

    return count;
}

//helper function for checking complete tree
bool NgramTree::checkCompleteHelper(NgramTreeNode* root, int index, int nodeNumber) {
    //Check if the tree is empty first
    if (root == NULL) {
        return true;
    }
    else if (index >= nodeNumber) {
        return false;
    }
    else {
        return (checkCompleteHelper(root->leftChild, 2 * index + 1, nodeNumber) && checkCompleteHelper(root->rightChild, 2 * index + 2, nodeNumber));
    }
}

//computes and returns whether or not the current tree is a complete tree
bool NgramTree::isComplete() {
    int index = 0;
    int number = getTotalNgramCount();

    return checkCompleteHelper(root, index, number);
}

//helper function for checking full tree
bool NgramTree::isFullTreeHelper(NgramTreeNode* root) {
    //Check if the tree is empty first
    if (root == NULL) {
        return true;
    }

    //Check if the node is a leaf
    else if ((root->leftChild) == NULL && (root->rightChild) == NULL) {
        return true;
    }

    //Check if both left and right childs are not NULL and both left and right subtrees are full
    else if ((root->leftChild) != NULL && (root->rightChild) != NULL) {
        return (isFullTreeHelper(root->leftChild) && isFullTreeHelper(root->rightChild));
    }

    else {
        return false;
    }
}

//computes and returns whether or not the current tree is a full tree
bool NgramTree::isFull() {
    return isFullTreeHelper(root);
}


