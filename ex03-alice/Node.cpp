#include <iostream>
#include "Node.h"

using namespace ds_course;
using namespace std;

Node::Node(int vv) {
    val = vv;
}

int Node::getVal() const {
    return this->val;
}

void Node::addChild(const Node& nodeChild) {
    this->children.push_back(nodeChild);
}

void Node::reflect() {
//    reverse(children.begin(), children.end());
    // Place your code to reverse the vector of the children
    // And also call this recursively ... all the children
}

vector<int> Node::getChildren() {
    vector<int> childr;
    // these two for loops are the same (IDE suggested use range based)
//    for(auto i = this->children.begin(); i != this->children.end(); i++)
//        childr.push_back(i->getVal());
    for(auto & i : this->children)
        childr.push_back(i.getVal());

    return childr;
}

void Node::printPreorder() {
    cout << "Printing..:)" << endl;
}