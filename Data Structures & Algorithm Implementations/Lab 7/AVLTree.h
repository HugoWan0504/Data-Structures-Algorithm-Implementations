#ifndef __AVLTREE_H__
#define __AVLTREE_H__
#include "Node.h"
#include <string>
#include <fstream>
using namespace std;

class AVLTree {
   private:
      Node* root;

   public:
      //default constructor
      AVLTree(){
         root = nullptr;
      }

      //Insert an item to the binary search tree and perform rotation if necessary.
      void insert(const string &newItem){
         Node* newNode = new Node(newItem);
         insert(root, newNode);
      }

      //Return the balance factor of a given node.
      int balanceFactor(Node* givenNode){
         int BFResult = height(givenNode->leftchild) - height(givenNode->rightchild);;
         return BFResult;
      }

      //Traverse and print the tree in inorder notation. 
      //Print the string followed by its balance factor in parentheses 
      //followed by a, and one space.
      void printBalanceFactors(){
         printBalanceFactors(root); 
         cout << endl;
      }



      // Generate dotty file and visualize the tree using dotty program. 
      //Call this function before and after rotation.
      void visualizeTree(const string &outputFilename){
         ofstream outFS(outputFilename.c_str());
         if(!outFS.is_open()){
            cout<<"Error"<<endl;
            return;
         }
         outFS<<"digraph G {"<<endl;
         visualizeTree(outFS,root);
         outFS<<"}";
         outFS.close();
         string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
         string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
         system(command.c_str());
      }
   
   private:
      //Find and return the closest unbalanced node 
      //(with balance factor of 2 or -2) to the inserted node.
      void findUnbalancedNode (Node*);
      //Implement four possible imbalance cases and update the parent of the given node.
      void rotate(Node* );
      //Rotate the subtree to left at the given node and returns the new subroot.
      void rotateLeft (Node* );
      //Rotate the subtree to right at the given node and returns the new subroot.
      void rotateRight(Node* );
      void printBalanceFactors(Node *currNode) {
         if(currNode != nullptr) {
            printBalanceFactors(currNode->leftchild); 
            cout << currNode->data << "(" << balanceFactor(currNode) << "), "; 
            printBalanceFactors(currNode->rightchild); 
         }
      }

      void visualizeTree(ofstream &outFS, Node *n){
         if(n){
            if(n->leftchild){
               visualizeTree(outFS,n->leftchild);
               outFS<<n->data <<" -> " <<n->leftchild->data<<";"<<endl;    
            }

            if(n->rightchild){
               visualizeTree(outFS,n->rightchild);
               outFS<<n->data <<" -> " <<n->rightchild->data<<";"<<endl;    
            }
         }
      }
   
   public:
   //more helper functions
      void insert(Node* ,Node* );
      int height(Node* ) const;
      void height(int , int & , Node* ) const;  
      void setChild(Node* , string, Node* ); 
      void replaceChild(Node* , Node* , Node* );

};

#endif /* __AVLTREE_H__ */

