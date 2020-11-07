#include "BinaryTree.h"

using namespace std;

ds_course::BinaryTree::BinaryTree() {
    rootInserted = false;
    root = nullptr;
}

ds_course::BinaryTree::~BinaryTree() {

}

//void ds_course::BinaryTree::insert(int parentKey, int childKey, char pos) {
//    Alien* parentAl = nullptr;
//    if (parentKey > 0) {
//        parentAl = search(parentKey, root);
//        if (parentAl == nullptr) {
//            std::cout << "[ERROR] Parent not found." << std::endl;
//            exit(-1);
//        }
//    }
//
//
//    switch (pos) {
//        case 'L':
//            parentAl->setLeft(childKey);
//            break;
//        case 'R':
//            parentAl->setRight(childKey);
//            break;
//        case 'T':
//            root = new Alien(childKey);
//            rootInserted = true;
//            break;
//        default:
//            cout << "[ERROR] Not recognized command." << endl;
//            exit(-1);
//    }
//}

ds_course::Alien* ds_course::BinaryTree::search(int key, Alien* current) {

    Alien* temp_left = nullptr;
    Alien* temp_right = nullptr;

    if (current == nullptr) {
        return nullptr;
    }

    if (current->getNum() == key) {
        return current;
    }

    if (current->getLeft() != nullptr) {
        temp_left = search(key, current->getLeft());
        if (temp_left != nullptr)
            return temp_left;
    }

    if (current->getRight() != nullptr) {
        temp_right = search(key, current->getRight());
        if (temp_right != nullptr)
            return temp_right;
    }

    return nullptr;
}

void ds_course::BinaryTree::merge_trees(ds_course::BinaryTree *bt) {

}

void ds_course::BinaryTree::destroy_tree() {

}

std::string ds_course::BinaryTree::getFavRelatives(int key) {
    return std::string();
}

// 2 out of class functions
// 1.
void printBT(const std::string& prefix, ds_course::Alien *node, bool isLeft) {
    if( node != nullptr ) {
        std::cout << prefix;

//        std::cout << (isLeft ? "├──" : "└──" );
        std::cout << (isLeft ? "|-" : "|_" );

        // print the value of the node
        std::cout << node->getNum() << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    "), node->getLeft(), true);
        printBT( prefix + (isLeft ? "|   " : "    "), node->getRight(), false);
    }
}
// 2.
void printBT(ds_course::Alien* node) {
    printBT("", node, false);
}

void ds_course::BinaryTree::displayTree() {
    printBT(root);
}

ds_course::Alien *ds_course::BinaryTree::getRoot() {
    return root;
}

void ds_course::BinaryTree::setRoot(int nn) {
    root = new Alien(nn);
}
