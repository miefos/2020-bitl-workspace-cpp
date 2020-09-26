#include <iostream>
#include "Node.h"
#include <deque>
#include <algorithm>

using namespace ds_course;
using namespace std;

Node::Node(int vv) {
    val = vv;
}

int Node::getVal() const {
    return this->val;
}

void Node::addChild(Node* nodeChild) {
    this->children.push_back(nodeChild);
}

void Node::reflect() {
    if (this->children.empty())
        return void();

    reverse(children.begin(), children.end());

    vector<int> childr = this->getChildren();

    for (int i = 0; i < childr.size(); i++) {
        this->children.at(i)->reflect();
    }

}

vector<int> Node::getChildren() { // returns vector children values
    vector<int> childr;

    for(auto & i : this->children) // the same as this: for(auto i = this->children.begin(); i != this->children.end(); i++)
        childr.push_back(i->getVal());

    return childr;
}

void Node::printPreorder() {
    if (this->children.empty())
        return void();

    deque<Node*> myqueue;
    cout << this->getVal() << " ";
    vector<int> childr = this->getChildren();
    int childr_size = childr.size();
    int last_in_row = childr_size - 1;

    for (int i = 0; i < childr_size; i++) {
        if (i == last_in_row) {
            cout << childr.at(i);
        } else {
            cout << childr.at(i) << " ";
        }
        myqueue.push_back(this->children.at(i));
    }

    cout << endl;

    while (!myqueue.empty()) {
        myqueue.front()->printPreorder();
        myqueue.pop_front();
    }
}

void Node::setParentVal(int pval) {
    this->parentVal =  pval;
}

int Node::getParentVal() const {
    return this->parentVal;
}
