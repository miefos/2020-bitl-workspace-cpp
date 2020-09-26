#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "Node.h"

using namespace std;
using namespace ds_course;

int main() {
    string inputLine;
    map<int, Node*> nodes;

    while (getline(cin, inputLine) && inputLine != "0") {
        // split by whitespace ("explode" function)
        istringstream iss(inputLine);

        // first int is parent node val
        int parentVal;
        iss >> parentVal;
        Node* parentNode;

        if (nodes.find(parentVal) != nodes.end())
            parentNode = nodes.find(parentVal)->second;
        else
            nodes.insert(pair<int, Node*>(parentVal, parentNode = new Node(parentVal)));

        // first int is taken... now all other ints are children
        for(int s; iss >> s; ) {
            Node* childNode;
            if (nodes.find(s) != nodes.end())
                childNode = nodes.find(s)->second;
            else
                nodes.insert(pair<int, Node*>(s, childNode = new Node(s)));

            parentNode->addChild(childNode);
        }

    }


    // only for testing
    int parentVal = 1;
    Node* parentNode = nodes.find(parentVal)->second;
    parentNode->reflect();
    parentNode->printPreorder();


    cout << ('0') << endl;

    return 0;
}

