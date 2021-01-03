#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include "BinaryTree.h"
#include "Alien.h"
#include "LinkedList.h"

using namespace std;
using namespace ds_course;

int main() {
    string Line;
    LinkedList ll;

//    ll.insertAlien(0,7,'T');
//    ll.insertAlien(7,2,'L');
//    ll.insertAlien(2,4,'L');
//    ll.insertAlien(7,9,'R');
//    ll.insertAlien(9,5,'L');
//    ll.insertAlien(5,1,'L');
//    ll.insertAlien(5,6,'R');
//    ll.insertAlien(6,111,'R');
//    ll.inorderPrint(ll.searchAlienInAllTrees(7));
//    ll.findFavorites(6);
//
//    return 0;

    while(getline(cin, Line)) {
        istringstream iss(Line);
        vector<string> tokens{istream_iterator<string>{iss},
                              istream_iterator<string>{}};
        // start processing
        char cmd = tokens[0][0];

        if (tokens.size() == 1) {
            if (cmd == 'F') {
//                ll.inorder(ll.searchAlienInAllTrees(7));
                return 0; // finish program
            } else {
                cout << "[ERROR] Command not recognized" << endl;
                return -1;
            }
        } else if (tokens.size() == 2) {
            if (cmd == 'T') {
                ll.insertAlien(0, stoi(tokens[1]), 'T');
            } else if (cmd == '?') {
                ll.findFavorites(stoi(tokens[1]));
            }
        } else if (tokens.size() == 3) {
            int parent = stoi(tokens[1]);
            int child = stoi(tokens[2]);

            if (cmd == 'L') {
                ll.insertAlien(parent, child, 'L');
            } else if (cmd == 'R') {
                ll.insertAlien(parent, child, 'R');
            }
        }
    }

    return 0;
}

