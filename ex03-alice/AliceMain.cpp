#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "Node.h"

using namespace std;
using namespace ds_course;

int main() {
    string inputString;
    string inputLine;
    map<int, Node> nodes;

    while (getline(cin, inputLine) && inputLine != "0") {
        // split by whitespace ("explode" function)
        istringstream iss(inputLine);

        // first int is parent node val
        int parentVal;
        iss >> parentVal;
        Node parentNode(parentVal);
        nodes.insert(pair<int, Node>(parentVal,parentNode));

        // first int is taken... now all other ints are children
        for(int s; iss >> s; ) {
            parentNode.addChild(Node(s));
        }

        // print children
        cout << "Printing children of " << parentVal << endl;
        vector<int> childr = parentNode.getChildren();
        for (int i : childr) {
            cout << i << endl;
        }
    }





//    nodes.insert(pair<int, Node>(1,Node(3))); // Set
//    nodes.insert(pair<int, Node>(1,Node(5))); // No effect (val remains 3)
//    nodes.insert(pair<int, Node>(1,Node(7))); // No effect (val remains 3)
//    nodes.insert(pair<int, Node>(2,Node(9)));
//    nodes.insert(pair<int, Node>(3,Node(27)));
//    nodes.insert(pair<int, Node>(5,Node(27)));
//
//    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
//        cout << it->first << " ";
//        cout << it->second.getVal() << endl;
//    }


//    cout << nodes.find(5)->second.getVal() << endl;



//    cout << "Hello" << endl;
//    Node n1(13);
//    cout << "Node has val = " << n1.getVal() << endl;



//    Node n1(1);
//    Node n2(2);
//    Node n3(3);
//    Node n4(4);
//    Node n5(5);
//    Node n6(6);
//    Node n7(7);
//    Node n8(8);
//
//    n1.addChild(n2);
//    n1.addChild(n3);
//    n1.addChild(n4);
//    n1.addChild(n5);
//    n1.addChild(n6);
//    n1.addChild(n7);
//
//    vector<int> childr = n1.getChildren();
//    for (int i = 0; i < childr.size(); i++) {
//        cout << childr.at(i) << endl;
//    }




//
//    n1.reflect();
//    n1.printPreorder();
//
//    map<int, Node> myMap;
//    n5.addChild(n8);
//    n3.addChild(n6);
//    n3.addChild(n7);
//    myMap.insert(pair<int, Node>(3,n3));
//
//    myMap.find(2);

    return 0;
}

