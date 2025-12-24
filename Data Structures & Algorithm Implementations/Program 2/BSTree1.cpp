#include <iostream>
#include "BSTree.h"
#include "Node.h"
#include <string>

using namespace std;

//implementation of the helper functions
//including insert, search, height, remove, and preOrder/postOrder/inOrder Prints

//private helper function for insert
//recursively inserts a value into the BST
void BSTree::insert(Node* root, const string& newString){
    //add a new node to an empty tree
    if (root == nullptr) {
        root = new Node(1, newString);
    } 
    //if key is lesser, add to left
    else if (root->getdata() > newString) {
        insert(root->leftchild, newString);
    } 
    //if key is larger, add to right
    else if (root->getdata() < newString) {
        insert(root->rightchild, newString);
    }
    //count++
    else {
        root->countIncrease();
    }
}


//private helper function for search
bool BSTree::search(Node* temp, const string& key) const{
    //if empty, false
    if (temp == nullptr) {
        return false;
    } 
    //if key is lesser, search left
    else if (temp->getdata() > key) {
        return search(temp->leftchild, key);
    } 
    //if key is larger, search right
    else if (temp->getdata() < key) {
        return search(temp->rightchild, key);
    }
    return true;
}

//private helper function for remove
void BSTree::remove(Node* &temp, const string& key){
    if (temp == nullptr){
        return;
    }
    //if key is lesser, recursive to its leftchild
    if (temp->getdata() > key){
        remove(temp->leftchild, key);
    }
    //if key is larger, recursive to its rightchild
    else if (temp->getdata() < key){
        remove(temp->rightchild, key);
    }
    else{
        //count--
        if (temp->getcount() > 1){
            temp->countDecrease();
        }
        else{  
            //check no children
            if (temp->leftchild == nullptr && temp->rightchild == nullptr){
                delete temp;
                temp = nullptr;
            }
            //check no leftchild
            else if (temp->leftchild == nullptr){
                Node* left = temp;
                left = left->rightchild;
            }
            //check no rightchild
            else if (temp->rightchild == nullptr){
                Node *right = temp;
                right = right->leftchild;
            }
            //check leaf
            else{
                temp->getdata() = smallest(temp->rightchild);
                remove(temp->rightchild, temp->getdata());
            }
        }
    }
}

//private helper function for largest
string BSTree::largest(Node *node) const {
    if (node->rightchild == nullptr) {
        return node->getdata();
    } else {
        return largest(node->rightchild);
    }
}

//private helper function for smallest
string BSTree::smallest(Node* node) const{
    if (node->leftchild == nullptr) {
        return node->getdata();
    } else {
        return smallest(node->leftchild);
    }
}

//private helper function for height
int BSTree::height(Node* temp) const{
    //if empty, return -1
    if (temp == nullptr){
        return -1;
    }
    else{
        int leftHeight = height(temp->leftchild);
        int rightHeight = height(temp->rightchild);

        //compare and return the larger height level
        if (leftHeight > rightHeight){
            return leftHeight + 1;
        }
        else{
            return rightHeight + 1;
        }
    }
}

//private helper function for preOrderPrint
//recursively prints tree values in preOrder
//Print/left/right
void BSTree::preOrder(Node* root) const{
    if (root != nullptr) {
        cout << root->getdata() << "(" << root->getcount() << "), ";
        preOrder(root->leftchild);
        preOrder(root->rightchild);
    }
    return;
}

//private helper function for postOrderPrint
//recursively prints tree values in postOrder
//left/right/Print
void BSTree::postOrder(Node* root) const{
    if (root != nullptr) {
        postOrder(root->leftchild);
        postOrder(root->rightchild);
        cout << root->getdata() << "(" << root->getcount() << "), ";
    }
    return;
}

//private helper function for inOrderPrint
//recursively prints tree values inOrder
//left/Print/right
void BSTree::inOrder(Node* root) const{
    if (root != nullptr) {
        inOrder(root->leftchild);
        cout << root->getdata() << "(" << root->getcount() << "), ";
        inOrder(root->rightchild);
    }
    return;
}

