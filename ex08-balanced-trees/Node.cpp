#include "Node.h"
#include <iostream>
#include <utility>
#include <sstream>

using namespace std;

namespace ds_course {
    int Node::get_height() {
        Node *node = this;
        if (node == nullptr) return 0;
        return node->height;
    }

    int Node::max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node *Node::newNode(std::string new_key) {
        Node* node = new Node();
        node->key = std::move(new_key);
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1; // initial height
        node->badness = 1; // initial badness

        return node;
    }

    Node *Node::rightRotate() {
        Node *y = this;
        Node *x = y->left;
        Node *subtree = x->right;

        x->right = y;
        y->left = subtree;

        y->height = max(y->left->get_height(), y->right->get_height()) + 1;
        x->height = max(x->left->get_height(), x->right->get_height()) + 1;

        return x;
    }

    int Node::getBadness(string key_to_find, string cmpMode) {
        Node* current = this;

        while (current != nullptr) {
            int comparison = compareAlgo(cmpMode, key_to_find, current->key);
            if (comparison == 0) {
                return current->badness;
            } else if (comparison < 0) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        return 0;
    }

    string Node::locateNodeByKey(string key_to_find, string cmpMode) {
        Node* current = this;
        string location = "*";

        while (current != nullptr) {
            int comparison = compareAlgo(cmpMode, key_to_find, current->key);
            if (comparison == 0) {
                return location;
            } else if (comparison < 0) {
                location += "L";
                current = current->left;
            } else {
                location += "R";
                current = current->right;
            }
        }

        return "N";
    }

    Node *Node::leftRotate() {
        Node *x = this;
        Node *y = x->right;
        Node *subtree = y->left;

        y->left = x;
        x->right = subtree;

        x->height = max(x->left->get_height(), x->right->get_height()) + 1;
        y->height = max(y->left->get_height(), y->right->get_height()) + 1;

        return y;
    }

    int Node::getBalance() {
        Node *N = this;
        if (N == nullptr)
            return 0;
        return N->left->get_height() - N->right->get_height();
    }

    int Node::compareLEX(string s1, string s2) {
        int firstCapital = 0;
        // 0 - not set; 1 - s1 has first capital; 2 - s2 has first capital
        // happens if s1,s2 are equal until some char but the char differs in capitalization
        int s1size = s1.size();
        int s2size = s2.size();

        for (int i = 0; i < s1size; i++) {
            // some potential problem checking
            if (!((s1[i] >= 65 && s1[i] <= 90) ||
                  (s1[i] >= 97 && s1[i] <= 122))) // not alphabet char
                s1[i] = 0; // if not alphachar, set 0
            if ((s2size - 1) < i) // too short (could cause segfaul if not set 0)
                s2 += "\0"; // if too short, add 0
            if (!((s2[i] >= 65 && s2[i] <= 90) ||
                  (s2[i] >= 97 && s2[i] <= 122))) // not alphabet char
                s2[i] = 0; // if not alphachar, set 0

            if (s1[i] == s2[i]) { // a == a
                continue;
            } else if (s1[i] == s2[i] + 32) { // A == a
                if (firstCapital == 0) firstCapital = 1;
                continue;
            } else if (s1[i] == s2[i] - 32) { // a == A
                if (firstCapital == 0) firstCapital = 2;
                continue;
            }

            // happens only if not prefix in any capitalization
            if (toupper(s1[i]) < toupper(s2[i])) {
                return -1;
//                    cout << s1 << " is smaller than " << s2 << endl; return 2; // should be -1
            } else { // larger (cannot be equal)
                return 1;
//                    cout << s1 << " is larger than " << s2 << endl; return 1;
            }
        }

        // happens only if prefix
        if (s1size == s2size) {
            if (firstCapital == 0) {
                return 0;
//                    cout << "Are equal.\n";
            } else if (firstCapital == 2) {
                return -1;
//                    cout << "s1 is smaller.\n";
            } else if (firstCapital == 1) {
                return 1;
//                    cout << "s1 is larger.\n";
            } else {
                return -10;
            }
        } else {
            return -1;
//                cout << "s1 is smaller (prefix with s1size!=s2size).\n";
        }
    }

    int Node::compareCOLEX(string s1, string s2) {
        // do not change this first part or be aware that after for cycle something might break
        int s1size = s1.size(), s2size = s2.size();
        bool smallest_str_is_first = true;
        if (s1size > s2size) smallest_str_is_first = false;

        string smallest_str = smallest_str_is_first ? s1:s2;
        string largest_str = smallest_str_is_first ? s2:s1;

        int firstCapital = 0;
        // 0 - not set; 1 - s1 has first capital; 2 - s2 has first capital
        // happens if s1,s2 are equal until some char but the char differs in capitalization


        for (
                int i = smallest_str.size() - 1, j = largest_str.size() - 1;
                i >= 0;
                i--, j--) {
            if (smallest_str[i] == largest_str[j]) {
                continue;
            } else if (smallest_str[i] == largest_str[j] + 32) { // A == a
                if (firstCapital == 0) firstCapital = 1;
                continue;
            } else if (smallest_str[i] == largest_str[j] - 32) { // a == A
                if (firstCapital == 0) firstCapital = 2;
                continue;
            }

            // happens only if not suffix in any capitalization
            if (toupper(smallest_str[i]) < toupper(largest_str[j])) {
                // smallest_str is smaller
                return smallest_str_is_first ? -1 : 1;
            } else { // larger (cannot be equal)
                // largest_str is smaller
                return smallest_str_is_first ? 1 : -1;
            }
        }

        // if you change algorithm which is smallest, might not work. Be careful.
        if (s1size == s2size) {
            if (firstCapital == 0) {
                return 0;
            } else if (firstCapital == 2) {
                return -1;
            } else if (firstCapital == 1) {
                return 1;
            } else {
                return -10;
            }
        } else {
            // smallest is suffix
            return smallest_str_is_first ? -1 : 1;
        }
    }

    int Node::compareAlgo(string mode, string s1, string s2) {
        if (mode == "LEX") {
            return Node::compareLEX(s1, s2);
        } else if (mode == "SHORTLEX") {
            // longer words precede shorter words...
            // if lengths equal, compare by lexicography
            if (s1.size() > s2.size())
                return 1;
            return Node::compareLEX(s1, s2);
        } else if (mode == "COLEX") {
            return Node::compareCOLEX(s1, s2);
        } else {
            return -10;
        }
    }

    string Node::dumpAVLUtil(Node* node, string start, string end, string cmpMode) {
        string ret_string;

        if (node != nullptr) {
            if (Node::compareAlgo(cmpMode, node->key, start) >= 0) {
                ret_string += dumpAVLUtil(node->left, start, end, cmpMode);
            }

            if (Node::compareAlgo(cmpMode, node->key, start) >= 0 &&
                Node::compareAlgo(cmpMode, node->key, end)   <= 0    ) {
                ret_string += " ";
                ret_string += "(";
                ret_string += node->key;
                ret_string += ",";

                ostringstream badness_string;
                badness_string << node->badness;

                ret_string += badness_string.str();
                ret_string += ")";
            }

            if (Node::compareAlgo(cmpMode, node->key, end) <= 0) {
                ret_string += dumpAVLUtil(node->right, start, end, cmpMode);
            }
        }

        return ret_string;
    }

    string Node::dumpAVL(string start, string end, string cmpMode) {
        if (start == "_") {
            Node *minNode = Node::minValueNode();
            if (minNode != nullptr)
                start = minNode->key;
            else
                return "";
        }

        if (end == "_") {
            Node *maxNode = Node::maxValueNode();
            if (maxNode != nullptr)
                end = maxNode->key;
            else
                return "";
        }

        return dumpAVLUtil(this, std::move(start), std::move(end), cmpMode);
    }

    Node* Node::insert(string keyn, string cmpMode)
    {
        Node *node = this;

        // should not happen
        if (node == nullptr)
            return(Node::newNode(keyn));

        if (compareAlgo(cmpMode, keyn, node->key) < 0)
            node->left = node->left->insert(keyn, cmpMode);
        else if (compareAlgo(cmpMode, keyn, node->key) > 0)
            node->right = node->right->insert(keyn, cmpMode);
        else { // equal keys increase badness
            node->badness += 1;
            return node;
        }

        // update height
        node->height = 1 + Node::max(node->left->get_height(), node->right->get_height());

        // get balance
        int balance = node->getBalance();

        // right rotation
        if (balance > 1 && compareAlgo(cmpMode, keyn, node->left->key) < 0)
            return node->rightRotate();

        // left rotation
        if (balance < -1 && compareAlgo(cmpMode, keyn, node->right->key) > 0)
            return node->leftRotate();

        // left right rotation
        if (balance > 1 && compareAlgo(cmpMode, keyn, node->left->key) > 0) {
            node->left = node->left->leftRotate();
            return node->rightRotate();
        }

        // right left rotation
        if (balance < -1 && compareAlgo(cmpMode, keyn, node->right->key) < 0)
        {
            node->right = node->right->rightRotate();
            return node->leftRotate();
        }

        return node;
    }

    Node* Node::eraseNode(const std::string& key, string cmpMode) {
        Node *root = this;

        if (root == nullptr)
            return root;

        if (compareAlgo(cmpMode, key, root->key) < 0)
            root->left = root->left->eraseNode(key, cmpMode);
        else if (compareAlgo(cmpMode, key, root->key) > 0)
            root->right = root->right->eraseNode(key, cmpMode);
        else {
            // node has only one child or no child
            if((root->left == nullptr ) ||
               (root->right == nullptr)) {
                Node *temp = root->left ? root->left : root->right;
                if (temp == nullptr) { // no child case
                    temp = root;
                    root = nullptr;
                } else // one child case
                    *root = *temp;
                free(temp);
            } else {
                Node* temp = root->right->minValueNode();

                root->key = temp->key;
                root->badness = temp->badness;

                root->right = root->right->eraseNode(temp->key, cmpMode);
            }
        }

        // if had only 1 node
        if (root == nullptr)
            return root;

        // update height
        root->height = 1 + max(root->left->get_height(), root->right->get_height());

        // get balance
        int balance = root->getBalance();

        // left-left rotation
        if (balance > 1 && root->left->getBalance() >= 0)
            return root->rightRotate();

        // left right rotation
        if (balance > 1 && root->left->getBalance() < 0) {
            root->left = root->left->leftRotate();
            return root->rightRotate();
        }

        // right-right rotation
        if (balance < -1 &&
            root->right->getBalance() <= 0)
            return root->leftRotate();

        // right-left rotation
        if (balance < -1 && root->right->getBalance() > 0) {
            root->right = root->right->rightRotate();
            return root->leftRotate();
        }

        return root;
    }

    // get leftmost leaf
    Node *Node::minValueNode() {
        Node* current = this;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    // get rightmost leaf
    Node *Node::maxValueNode() {
        Node* current = this;

        while (current->right != nullptr)
            current = current->right;

        return current;
    }


    void Node::eraseAllNodes(Node *root, string cmpMode) {
        while (root != nullptr) {
            root = root->eraseNode(root->key, cmpMode);
        }
    }
}