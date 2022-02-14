/**
* Title: AVLTree

* Author: Melis Atun

* ID: 21901865

* Assignment: 3

* Description: AVLTree.h file

*/

#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <stdio.h>
using namespace std;

struct TreeNode {
    int item;
    int height;
    TreeNode* leftPtr;
    TreeNode* rightPtr;
    TreeNode(int value) {
        item = value;
        leftPtr = NULL;
        rightPtr = NULL;
    }
};

class AVLTree {

public:
    AVLTree(); //constructor
    ~AVLTree(); //destructor

    //functions
    void insert(int value);
    int getNumberOfRotations();

    //helper functions
    void insertHelper(TreeNode*& root, int value);
    void deleteTree(TreeNode* root);
    int findHeight(TreeNode* root);
    TreeNode* singleLeftRotation(TreeNode* root);
    void doubleRightLeftRotation(TreeNode*& parent);
    TreeNode* singleRightRotation(TreeNode* root);
    void doubleLeftRightRotation(TreeNode*& parent);
    TreeNode* updateHeight(TreeNode* node);

private: 
    TreeNode *root;
    int count;
};

#endif
