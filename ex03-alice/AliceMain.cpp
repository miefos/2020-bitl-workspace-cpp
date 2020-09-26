#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "Node.h"

using namespace std;
using namespace ds_course;

int getRootValue(map<int, Node*> nodes, int startValue) { // startValue is changed over function (locally)
    Node* existingParentNode;

    while (true) {
        if (nodes.find(startValue) != nodes.end()) { // exists
            existingParentNode = nodes.find(startValue)->second;
        } else {
            return -1; // if error
        }
        if (existingParentNode->getParentVal() != -1) {
            startValue = existingParentNode->getParentVal();
        } else {
            return startValue;
        }
    }
    return -1; // should not happen
}

int main() {
    string inputLine;
    int init;
    int count = 0;
    map<int, Node*> nodes;

    while (getline(cin, inputLine) && inputLine != "0") {
        // split by whitespace ("explode" function)
        istringstream iss(inputLine);

        // first int is parent node val
        int parentVal;
        iss >> parentVal;
        Node* parentNode;

        if (count == 0) {
            init = parentVal;
            count++;
        }

        if (nodes.find(parentVal) != nodes.end()) { // parent val already set (as children)
            parentNode = nodes.find(parentVal)->second;
            init = getRootValue(nodes, parentVal);
//            cout << "Case 1: parentVal is " << parentVal << endl;
        }
        else {
            nodes.insert(pair<int, Node *>(parentVal, parentNode = new Node(parentVal)));
//            cout << "Case 2: parentVal is " << parentVal << endl;
        }

        // first int is taken... now all other ints are children
        for(int s; iss >> s; ) {
            Node* childNode;
            if (nodes.find(s) != nodes.end()) { // child val already set (as parent)
                childNode = nodes.find(s)->second;
                init = getRootValue(nodes, parentVal);
                if (childNode->getParentVal() == -1)
                    childNode->setParentVal(parentVal);
            }
            else {
                childNode = new Node(s);
                nodes.insert(pair<int, Node *>(s,childNode));
                childNode->setParentVal(parentVal);
            }

            parentNode->addChild(childNode);
        }

    }

    Node* parentNode = nodes.find(init)->second;
    parentNode->reflect();
    parentNode->printPreorder();


    cout << ('0') << endl;


    return 0;
}

