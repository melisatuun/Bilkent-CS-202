/**
* Title: AVLTree

* Author: Melis Atun

* ID: 21901865

* Assignment: 3

* Description: AVLTree.cpp file

*/

#include "AVLTree.h"
#include <iostream>
#include <cmath>
using namespace std;

//constructor
AVLTree::AVLTree() : root(NULL) {
    count = 0;
}

//destructor
AVLTree::~AVLTree() {
    deleteTree(root);
}

//delete tree helper function
void AVLTree::deleteTree(TreeNode* root) {
    if (root != NULL) {
        deleteTree(root->leftPtr);
        deleteTree(root->rightPtr);
    }
}

//insert function
void AVLTree::insert(int value) {
    if (root == NULL)
        root = new TreeNode(value);

    insertHelper(root, value);
}

//insert helper function
void AVLTree::insertHelper(TreeNode*& root, int value) {
    //inserting a new item to AVL tree
    if (value < (root->item)) {
        if (root->leftPtr == NULL) //no left child, so create one
            root->leftPtr = new TreeNode(value);
        else
            insertHelper(root->leftPtr, value); //there is a left child, so find the place to insert recursively
    }
    else {
        if (root->rightPtr == NULL) //no right child, so create one
            root->rightPtr = new TreeNode(value);
        else
            insertHelper(root->rightPtr, value); //there is a right child, so find the place to insert recursively
    }
    int left = findHeight(root->leftPtr);
    int right = findHeight(root->rightPtr);

    if (left - right > 1) { //if left subtree is taller than right subtree
        if (value < root->leftPtr->item)
            singleRightRotation(root);
        else
            doubleLeftRightRotation(root);
    }

    else if (right - left > 1) { //if right subtree is taller than left subtree
        if (value > root->rightPtr->item)
            singleLeftRotation(root);
        else
            doubleRightLeftRotation(root);
    }
}

//find height function
int AVLTree::findHeight(TreeNode* root) {
    if (root == NULL) 
        return 0;
    else {
        int left;
        int right;
        left = findHeight(root->leftPtr);
        right = findHeight(root->rightPtr);
        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
}

//single left rotation function
TreeNode* AVLTree::singleLeftRotation(TreeNode* root) {
        TreeNode* node = root->rightPtr;
        TreeNode* otherNode = node->leftPtr;

        root->rightPtr = otherNode;
        node->leftPtr = root;

        //update heights
        node = updateHeight(node);
        root = updateHeight(root);

        count++;
        return node;
}

//double right and left rotation function
void AVLTree::doubleRightLeftRotation(TreeNode*& parent) {
    singleRightRotation(parent->rightPtr);
    singleLeftRotation(parent);
    count++;
}

//single right rotation function
TreeNode* AVLTree::singleRightRotation(TreeNode* root) {
    TreeNode* node = root->leftPtr;
    TreeNode* otherNode = node->rightPtr;

    root->leftPtr = otherNode;
    node->rightPtr = root;

    //update heights 
    node = updateHeight(node);
    root = updateHeight(root);

    count++;
    return node;
}

//double right rotation function
void AVLTree::doubleLeftRightRotation(TreeNode*& parent) {
    singleLeftRotation(parent->leftPtr);
    singleRightRotation(parent);
    count++;
}

//update height function
TreeNode* AVLTree::updateHeight(TreeNode* node) {
    node->height = 1 + max(findHeight(node->leftPtr), findHeight(node->rightPtr));
    return node;
}

//get number of rotations function
int AVLTree::getNumberOfRotations() {
    return count;
}

