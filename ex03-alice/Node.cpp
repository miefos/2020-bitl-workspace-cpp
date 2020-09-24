#include "Node.h"

using namespace ds_course;
using namespace std;

Node::Node(int vv) {
    val = vv;
//    children;
}

int Node::getVal() {
    return this->val;
}

void Node::addChild(Node nn) {

}

void Node::reflect() {
    reverse(children.begin(), children.end());
    // Place your code to reverse the vector of the children
    // And also call this recursively ... all the children
}

vector<int> Node::getChildren() {
    return vector<int>();
}

void Node::printPreorder() {

}


/*
struct Node {
private:
    int val;
    vector <Node> children;

public:
    Node(int vv);
    void addChild(Node nn);
    void reflect();
    int getVal();
    vector<int> getChildren();
};
 */