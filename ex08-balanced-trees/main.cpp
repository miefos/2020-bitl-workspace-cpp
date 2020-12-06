#include <string>
#include <sstream>
#include <iostream>
#include <Node.h>

#define MAX_WORDS_PER_LINE 100
#define MAX_WORD_SIZE 30

using namespace std;
using namespace ds_course;

int main() {
    Node *root = nullptr;

    int line_num = 0;
    string orderMode;
    cin >> orderMode;

    line_num++;
    string Line;
    cin.ignore(256, '\n');

    while(getline(cin, Line)) {
        line_num++;
        istringstream iss(Line);
        string operators[MAX_WORDS_PER_LINE];
        char operation; 
        int i = 0;
        bool first = true;

        while (iss && i < MAX_WORDS_PER_LINE) {
            string temp;
            iss >> temp;
            if (temp.empty() || temp == "\n") // skip \n
               continue;
            if (first) {
                operation = temp[0];
                first = false;
                continue;
            }
            operators[i] = temp;
            i++;
        }

        if (operation == 'I') {
            if (i < 1) return -2;
            int j = 0;
            if (root == nullptr) {
                root = Node::newNode(operators[j]);
                j++;
            }
            for (; j < i; j++) {
                root = root->insert(operators[j], orderMode);
            }
        } else if (operation == 'G') {
            if (operators[0].empty()) return -1;
            string key = operators[0];
            int badness = root->getBadness(key, orderMode);
            cout << line_num << " (" << key << "," << badness << ")" << endl;
        } else if (operation == 'E') {
            if (i < 1) return -2;
            for (int j = 0; j < i; j++) {
                root = root->eraseNode(operators[j], orderMode);
            }
        } else if (operation == 'L') {
            if (operators[0].empty()) return -1;
            string key = operators[0];
            if (root != nullptr) {
                string location = root->locateNodeByKey(key, orderMode);
                cout << line_num << " " << location << endl;
            }
        } else if (operation == 'D') {
            string start = "_", end = "_";
            if (!(operators[0].empty())) start = operators[0];
            if (!(operators[1].empty())) end = operators[1];
            if (root != nullptr)
                cout << line_num << root->dumpAVL(start, end, orderMode) << endl;
        } else if (operation == 'F') {
            Node::eraseAllNodes(root, orderMode);
            return 0;
        } else {
            Node::eraseAllNodes(root, orderMode);
            cout << "Operation Err. " << endl;
            return -1;
        }
    }

    Node::eraseAllNodes(root, orderMode);

    return 0;
}