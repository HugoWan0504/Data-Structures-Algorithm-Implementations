#include <iostream>
#include "AVLTree.h"
#include <string>
#include <fstream>

using namespace std;

void AVLTree::insert(Node *currNode, Node *newNode) {
    if (!root){
        root = newNode; 
        root->parentNode = nullptr;
        return;
    }
    currNode = root;
    while (currNode){ 
        if (newNode->data == currNode->data) {
            currNode->count++; 
            currNode = nullptr;
        } 
        else if (newNode->data < currNode->data) {
            if (currNode->leftchild == nullptr) {
                currNode->leftchild = newNode;
                newNode->parentNode = currNode;
                currNode = nullptr;
            }
            else{
                currNode = currNode->leftchild;
            }
        }
        else {
            if (currNode->rightchild == nullptr) {
                currNode->rightchild = newNode;
                newNode->parentNode = currNode;
                currNode = nullptr;
            }
            else{
                currNode = currNode->rightchild;
            }
        }
    }
    newNode = newNode->parentNode;
    while (newNode){ 
        rotate(newNode); 
        newNode = newNode->parentNode; 
    }
}

int AVLTree::height(Node *currNode) const { 
    if (currNode != nullptr){
        int heightResult = 0;
        height(0, heightResult, currNode); 
        return heightResult - 1;
    }
    return -1;
}

void AVLTree::height(int countHeight, int &heightResult, Node *currNode) const {
    if(currNode != nullptr) {
        countHeight++; 
        if(countHeight > heightResult){
            heightResult = countHeight;
        }
        //recursively traverse tree
        height(countHeight, heightResult, currNode->leftchild);
        height(countHeight, heightResult, currNode->rightchild); 
    }
}

void AVLTree::rotate(Node *currNode) { 
    if (balanceFactor(currNode) == 2){
        if(balanceFactor(currNode->leftchild) == -1) {
            rotateLeft(currNode->leftchild);
        } 
        rotateRight(currNode);
    }
    else if (balanceFactor(currNode) == -2){
        if(balanceFactor(currNode->rightchild) == 1) { 
            rotateRight(currNode->rightchild); 
        } 
        rotateLeft(currNode);
    }
}

void AVLTree::rotateLeft(Node *currNode) {
    Node *temp = currNode->rightchild->leftchild;
    if (currNode->parentNode){ 
        replaceChild(currNode->parentNode,currNode,currNode->rightchild);
    } 
    else {
        root = currNode->rightchild; 
        root->parentNode = 0;
    }
    setChild(currNode->rightchild,"left",currNode); 
    setChild(currNode,"right",temp);
}

void AVLTree::rotateRight(Node *currNode) {
    Node *temp = currNode->leftchild->rightchild;
    if (currNode->parentNode){
        replaceChild(currNode->parentNode,currNode,currNode->leftchild);
    } 
    else {
        root = currNode->leftchild; 
        root->parentNode = 0;
    }
    setChild(currNode->leftchild,"right",currNode); 
    setChild(currNode,"left",temp);
}  

void AVLTree::setChild(Node *parent, string whichChild, Node *child) {
    if (whichChild == "left"){
        parent->leftchild = child;
    } 
    else{
        parent->rightchild = child;
    }
    if (child != nullptr){
        child->parentNode = parent;
    }
}

void AVLTree::replaceChild(Node *parent, Node *currNode, Node *newChild) {
    if (parent->leftchild == currNode) {
        setChild(parent, "left", newChild);
    } 
    else if (parent->rightchild == currNode) {
        setChild(parent, "right", newChild);
    }
}