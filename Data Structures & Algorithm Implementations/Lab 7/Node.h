#ifndef _NODE_H__
#define _NODE_H__

#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        friend class AVLTree;
        Node* leftchild;
        Node* rightchild;
        Node* parentNode;
        Node();
        Node(string dt);

    private:
        int count;
        string data;

};

#endif /* _NODE_H__ */
