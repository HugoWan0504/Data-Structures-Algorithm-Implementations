#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

Node::Node() {
    small = "";
    large = "";
    left = nullptr;
    middle = nullptr;
    right = nullptr;
    parent = nullptr;
}
bool Node::twoStr() const{
    return !large.empty();
}