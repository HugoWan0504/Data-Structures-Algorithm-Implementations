#ifndef __BSTREE_H__
#define __BSTREE_H__
#include "Node.h"
#include <string>
using namespace std;

class BSTree {
   private:
      Node *root;
   public:
      /* Constructors */
      /* Default constructor */
      BSTree(){
         root = nullptr;
      }

      ~BSTree(){
         delete this->root;
      }

      /* Mutators */
      /* Insert an item into the binary search tree. 
         Be sure to keep BST properties. 
         When an item is first inserted into the tree the count should be set to 1. 
         When adding a duplicate string (case sensitive), rather than adding another node, 
         the count variable should be incremented 
      */
      void insert(const string &newString){
         insert(this->root, newString);
      }

      /* Remove a specified string from the tree. 
         Be sure to maintain all bianry search tree properties. 
         If removing a node with a count greater than 1, just decrement the count, otherwise, 
         if the count is simply 1, remove the node.

         You MUST follow the remove algorithm shown in the slides and discussed in class or else 
         your program will not pass the test functions.
         
         When removing, 
         if removing a leaf node, simply remove the leaf. Otherwise, 
         if the node to remove has a left child, replace the node to remove with the largest 
         string value that is smaller than the current string to remove 
         (i.e. find the largest value in the left subtree of the node to remove). 
         If the node has no left child, replace the node to remove with the smallest value 
         larger than the current string to remove 
         (i.e. find the smallest value in the right subtree of the node to remove. 
      */
      void remove(const string &key){
         Node *temp = search(this->root, key);
         if (temp != nullptr){
            this->root = remove(this->root, key);
         }
      }

      /* Accessors */
      /* Search for a string in the binary search tree. 
         It should return true if the string is in the tree, and false otherwise. 
      */
      bool search(const string& key) const{
         Node* Root = root;
         if (Root != nullptr){
            if (Root->getdata() == key){
               return true;
            }
            if (search(Root->leftchild, key)){
               return true;
            }
            if (search(Root->rightchild, key)){
               return true;
            }
         }
         return false;
      }

      /* Find and return the largest value in the tree. Return an empty string if the tree is empty */
      string largest() const{
         Node* temp = this->root;

         //if tree has no roots, return empty.
         if (temp == nullptr) {
            return "";
         }

         //while there exists a rightchild, points to the furthest rightchild and return its data.
         while (temp->rightchild != nullptr) {
            temp = temp->rightchild;
         }
         return temp->getdata();
      }

      /* Find and return the smallest value in the tree. Return an emtpy string if the tree is empty */
      string smallest() const{
         Node* temp = this->root;

         //if tree has no roots, return empty.
         if (temp == nullptr) {
            return "";
         }

         //while there exists a leftchild, points to the furthest leftchild and return its data.
         while (temp->leftchild != nullptr) {
            temp = temp->leftchild;
         }
         return temp->getdata();
      }

      /* Compute and return the height of a particular string in the tree. 
         The height of a leaf node is 0 (count the number of edges on the longest path). 
         Return -1 if the string does not exist. 
      */
      int height(const string& key) const{
         Node *temp = search(this->root, key);
         if (temp != nullptr){
            return height(temp);
         }
         else{
            return -1;
         }
      }

      /* Printing */
      /* For all printing orders, each node should be displayed as follows:
         <string> (<count>)
         e.g. goodbye(1), Hello World(3)
      */
      void preOrder() const{
         preOrder(this->root);
      }
      void postOrder() const{
         postOrder(this->root);
      }
      void inOrder() const{
         inOrder(this->root);
      }

   //private helper function
   public:
      Node* search(Node* nodePtr, const string &key) const;
      Node* remove(Node* nodePtr, const string &key);
      int height(Node* nodePtr) const;
      void insert(Node *temp, const string &data);
      void preOrder(Node* temp) const;
      void postOrder(Node* temp) const;
      void inOrder(Node* temp) const;
};

#endif // __BSTREE_H__

