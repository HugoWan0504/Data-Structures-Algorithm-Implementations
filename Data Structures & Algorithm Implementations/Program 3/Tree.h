#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

class Tree {
private:
  Node *root;

public:
  Tree();
  ~Tree();
  void insert(const string &);
  void remove(const string &);
  bool search (const string &);
  void preOrder() const;
  void inOrder() const;
  void postOrder() const;
  void shifts(Node*);

private:
  // Add additional functions/variables here
  bool search (Node* node, const string &key);
  void preOrder(Node* temp) const;
  void postOrder(Node* temp) const;
  void inOrder(Node* temp) const;
  Node* deleteRoot(Node*);
  
};

#endif
