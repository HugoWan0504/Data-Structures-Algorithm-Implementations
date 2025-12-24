#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

Node::Node() {
    count = 0;
    data = "none";
    leftchild = nullptr;
    rightchild = nullptr;
}

Node::Node(int ct, string dt) {
    count = ct;
    data = dt;
    leftchild = nullptr;
    rightchild = nullptr;
}

