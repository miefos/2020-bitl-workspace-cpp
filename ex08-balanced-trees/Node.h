#include <iostream>

#ifndef EX08_BALANCED_TREES_NODE_H
#define EX08_BALANCED_TREES_NODE_H

using namespace std;

namespace ds_course {
    class Node {
    public:
        // variables
        string key;
        int badness;
        Node *left;
        Node *right;
        int height;

        // methods
        Node *rightRotate();
        Node *leftRotate();
        Node *insert(string keyn, string cmpMode);
        Node *eraseNode(const std::string& key, string cmpMode);
        Node *minValueNode();
        Node *maxValueNode();
        int getBalance();
        int get_height();
        int getBadness(string key_to_find, string cmpMode);
        string locateNodeByKey(string key_to_find, string cmpMode);
        string dumpAVL(string start, string end, string cmpMode);
        string dumpAVLUtil(Node *node, string start, string end, string cmpMode);

        // static methods
        static Node *newNode(std::string new_key);
        static int max(int a, int b);
        static int compareAlgo(string mode, string s1, string s2);
        static int compareLEX(string s1, string s2);
        static int compareCOLEX(string s1, string s2);
        static void eraseAllNodes(Node *temp, string cmpMode);
    };
}


#endif //EX08_BALANCED_TREES_NODE_H
