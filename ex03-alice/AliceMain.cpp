#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "Node.h"

using namespace std;
using namespace ds_course;

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

        if (nodes.find(parentVal) != nodes.end()) {
            parentNode = nodes.find(parentVal)->second;
//            cout << "Case 1: parentVal is " << parentVal << endl;
        }
        else {
            nodes.insert(pair<int, Node *>(parentVal, parentNode = new Node(parentVal)));
//            cout << "Case 2: parentVal is " << parentVal << endl;
        }

        // first int is taken... now all other ints are children
        for(int s; iss >> s; ) {
            Node* childNode;
            if (nodes.find(s) != nodes.end()) {
                childNode = nodes.find(s)->second;
                init = parentVal;
            }
            else
                nodes.insert(pair<int, Node*>(s, childNode = new Node(s)));

            parentNode->addChild(childNode);
        }

    }


    Node* parentNode = nodes.find(init)->second;
    parentNode->reflect();
    parentNode->printPreorder();


    cout << ('0') << endl;


    return 0;
}

