#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

Node::Node() {
    count = 0;
    data = "none";
    leftchild = nullptr;
    rightchild = nullptr;
    parentNode = nullptr;
}

Node::Node(string dt) {
    count = 1;
    data = dt;
    leftchild = nullptr;
    rightchild = nullptr;
    parentNode = nullptr;
}