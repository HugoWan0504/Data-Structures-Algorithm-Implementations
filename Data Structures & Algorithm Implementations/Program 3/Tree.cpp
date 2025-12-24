#include <iostream>
#include "Tree.h"
#include "Node.h"
#include <string>
#include <fstream>

using namespace std;

Tree::Tree(){
    root = nullptr;
}
Tree::~Tree(){
    delete deleteRoot(root);
}

Node* Tree::deleteRoot(Node* dRoot){
    //if root not empty, delete node's left/middle/right
    if (dRoot != nullptr){
        delete deleteRoot(dRoot->left);
        delete deleteRoot(dRoot->middle);
        delete deleteRoot(dRoot->right);
    }
    return dRoot;
}

bool Tree::search (const string &s){
    return search(root, s);
}
bool Tree::search (Node* node, const string &key){
    if (node != nullptr) {
        //compare the node values with key
        if (node->small == key || node->large == key) {
            return true;
        }
        else {
            //if key is leeser, go left
            if (key < node->small) {
                return search(node->left, key);
            }
            //if key is larger, go right
            else if (key > node->large) {
                return search(node->right, key);
            }
            //if same, search middle
            else {
                return search(node->middle, key);
            }
        }
    }
    //if node is empty, default return false
    return false;
}

void Tree::insert(const string &s){
    //if root is empty, assign new string to a new node
    if (root == nullptr){
        root = new Node();
        root->small = s;
    }
    else{
        Node* target = root;
        while (target->left){
            if (target->twoStr()){
                //if s is lesser, go left
                if (target->small > s){
                    target = target->left;
                }
                //if s is larger, go right
                else if (target->small < s){
                    target = target->right;
                }
                //if s is the same, go middle
                else{
                    target = target->middle;
                }
            }
            else{
                if (target->small > s){
                    target = target->left;
                }
                else{
                    target = target->middle;
                }
            }
        }

        if (target->twoStr()){
            string small;
            string middle;
            string large;
            if (target->small > s){
                small = s;
                middle = target->small;
                large = target->large;
            }
            else{
                small = target->small;
                if (target->large < s){
                    middle = target->large;
                    large = s;
                }
                else{
                    middle = s;
                    large = target->large;
                }
            }
            Node* smlNode = new Node();
            smlNode->small = small;
            Node* lrgNode = new Node();
            lrgNode->small = large;

            target->small = middle;
            target->large = "";
            target->left = smlNode;
            target->middle = lrgNode;
            target->right = nullptr;

            smlNode->parent = target;
            lrgNode->parent = target;

            shifts(target);
        }
        else{
            if (target->small > s){
                target->large = target->small;
                target->small = s;
            }
            else{
                target->large = s;
            }
        }
    }
}

void Tree::shifts(Node *node){
    if (node->parent){
        Node* parent = node->parent;
        if (parent->twoStr()){
            // Node is coming from the LEFT
            if (parent->small > node->small){
                Node* newLarge = new Node();
                // newLarge takes the parent's middle and right children
                newLarge->left = parent->middle;
                newLarge->left->parent = newLarge;
                newLarge->middle = parent->right;
                newLarge->middle->parent = newLarge;
                newLarge->small = parent->large;

                // Reset values of parent and insert the value from node
                parent->left = node;
                parent->middle = newLarge;
                parent->right = nullptr;
                parent->large = "";

                //Link parent value of newLarge
                newLarge->parent = parent;
            }
            // Node is coming from the RIGHT
            else if (parent->large < node->small){
                Node* newSmall = new Node();
                // newSmall takes the parent's left and middle children
                newSmall->left = parent->left;
                newSmall->left->parent = newSmall;
                newSmall->middle = parent->middle;
                newSmall->middle->parent = newSmall;
                newSmall->small = parent->small;

                // Reset values of parent and insert the value from node
                parent->left = newSmall;
                parent->middle = node;
                parent->right = nullptr;
                parent->small = parent->large;
                parent->large = "";

                //Link parent value of newSmall
                newSmall->parent = parent;
            }
            // Node is coming from the MIDDLE
            else{
                Node* newSmall = new Node();
                newSmall->small = parent->small;
                newSmall->left = parent->left;
                newSmall->left->parent = newSmall;
                newSmall->middle = node->left;
                newSmall->middle->parent = newSmall;

                Node* newLarge = new Node();
                newLarge->small = parent->large;
                newLarge->left = node->middle;
                newLarge->left->parent = newLarge;
                newLarge->middle = parent->middle;
                newLarge->middle->parent = newLarge;

                //Reset values
                parent->left = newSmall;
                parent->middle = newLarge;
                parent->right = nullptr;
                parent->small = node->small;
                parent->large = "";

                //Link parent values of newSmall and newLarge
                newSmall->parent = parent;
                newLarge->parent = parent;

                delete node;
            }

            shifts(parent);
        }
        // Moving up into the same node, dealing with children (base case!)
        else{
            // node from left
            if (parent->small > node->small){
                parent->large = parent->small;
                parent->small = node->small;
                parent->left = node->left;
                parent->right = parent->middle;
                parent->middle = node->middle;
            }
            // node from right
            else{
                parent->large = node->small;
                parent->middle = node->left;
                node->left->parent = parent;
                parent->right = node->middle;
                node->middle->parent = parent;
            }

            // Update parent
            node->left->parent = parent;
            node->middle->parent = parent;
            delete node;
        }
    }
}

void Tree::remove(const string &str){
    Node* searchNode = root;
    while (searchNode){
        //Compare and break if same
        if (searchNode->small == str || (searchNode->twoStr() && searchNode->large == str)){
            break;
        }
        //different
        else{
             // if str is lesser, go left
            if (searchNode->small > str){
                searchNode = searchNode->left;
            }
            else{
                // if str larger than both strings, go right
                if (searchNode->twoStr() && searchNode->large < str){
                    searchNode = searchNode->right;
                }
                //else go middle
                else{
                    searchNode = searchNode->middle;
                }
            }
        }
    }

    if (searchNode != nullptr){
        if (searchNode->twoStr()){
            if (str == searchNode->small){
                searchNode->small = searchNode->large;
                searchNode->large = "";
            }
            else{
                searchNode->large = "";
            }
        }
        else{
            Node* parent = searchNode->parent;
            if (parent) {
                if (str < parent->small) {
                    parent->left = nullptr;
                    parent->large = parent->middle->small;
                    parent->middle = nullptr;
                } else {
                    parent->middle = nullptr;
                    parent->large = parent->small;
                    parent->small = parent->left->small;
                    parent->left = nullptr;
                }
            }
            else{
                Node* temp = new Node();
                if (root->left) {
                    temp->small = root->left->small;
                    temp->large = root->middle->small;
                    root = temp;
                } 
                else {
                    root = nullptr;
                }
            }
        }
    }
}


void Tree::preOrder() const{
    preOrder(this->root);
}
void Tree::inOrder() const{
    inOrder(this->root);
}
void Tree::postOrder() const{
    postOrder(this->root);
}

void Tree::preOrder(Node* root) const{
    if (root != nullptr) {
        cout << root->small << ", ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void Tree::postOrder(Node* root) const{
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->small << ", ";
    }
}

void Tree::inOrder(Node* root) const{
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->small << ", ";
        inOrder(root->right);
    }
}