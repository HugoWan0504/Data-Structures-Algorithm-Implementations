#include <iostream>
#include "BSTree.h"
#include "Node.h"
#include <string>

using namespace std;

//implementation of the helper functions
//including insert, search, height, remove, and preOrder/postOrder/inOrder Prints

//private helper function for insert
//recursively inserts a value into the BST
void BSTree::insert(Node* root, const string& key){
    //if root empty, assign newNode
    if (root == nullptr){
        Node* newNode = new Node(1, key);
        this->root = newNode;
    }
    else {
        //if duplicated, count++
        if (root->getdata() == key){
            root->countIncrease();
        }
        //if key is lesser
        else if (root->getdata() > key){
            //check leftchild
            if (root->leftchild == nullptr){
                Node* newNode = new Node(1, key);
                root->leftchild = newNode;
            }
            //recursive
            else {
                insert(root->leftchild, key);
            }
        }
        //if key is larger
        else if (root->getdata() < key){
            //check rightchild
            if (root->rightchild == NULL){
                Node* newNode = new Node(1, key);  
                root->rightchild = newNode;
            }
            //recursive
            else {
                insert(root->rightchild, key);
            }
        }
    }
}


//private helper function for search
Node* BSTree::search(Node* temp, const string& key) const{
    //check temp
    if (!temp){
        return 0;
    }
    //if same, return temp
    if (temp->getdata() == key){
        return temp;
    }
    //if key is lesser, check leftchild
    else{
        if (temp->getdata() > key){
            return search(temp->leftchild, key);
        }
        //if key is larger, check rightchild
        else {
            return search(temp->rightchild, key);
        }
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

//private helper function for remove
Node* BSTree::remove(Node* temp, const string& key){
    if (temp == nullptr){
        return temp;
    }
    //if key is lesser, recursive to its leftchild
    if (temp->getdata() > key){
        temp->leftchild = remove(temp->leftchild, key);
    }
    //if key is larger, recursive to its rightchild
    else if (temp->getdata() < key){
        temp->rightchild = remove(temp->rightchild, key);
    }
    else{
        //count--
        if (temp->getcount() > 1){
            temp->countDecrease();
            return temp;
        }
        //check leftchild
        if (temp->leftchild != nullptr){
            Node *left = temp->leftchild;
            Node *parent = temp;
            while (left->rightchild != nullptr){
                parent = left;
                left = left->rightchild;
            }
            temp->setdata(left->getdata());
            temp->setcount(left->getcount());
            parent->rightchild = left->leftchild;
            free(left);
            return temp;
        }
        //check rightchild
        else if (temp->rightchild != nullptr){
            Node *right = temp->rightchild;
            Node *parent = temp;
            while (right->leftchild != nullptr){
                parent = right;
                right = right->leftchild;
            }
            temp->setdata(right->getdata());
            temp->setcount(right->getcount());
            parent->leftchild = right->rightchild;
            free(right);
            return temp;
        }
        //check leaf
        else{
            free(temp);
            return nullptr;
        }
    }
    return temp;
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
}
