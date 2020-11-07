#include "LinkedList.h"

ds_course::LinkedList::LinkedList() {
//    std::cout << "Linked list created!" << std::endl;
    head = NULL;
    tail = NULL;
}

ds_course::LinkedList::~LinkedList() {
//    std::cout << "Linked list destroyed!" << std::endl;
}

ds_course::BinaryTree *ds_course::LinkedList::addTree() {
//    std::cout << "Tree added!" << std::endl;
    BinaryTree* bt = new BinaryTree;
    bt->next = nullptr;

    if(head == nullptr) {
        head = bt;
        tail = bt;
    } else {
        tail->next = bt;
        tail = tail->next;
    }

    return bt;
}

ds_course::BinaryTree *ds_course::LinkedList::searchTreeForKey(int key) {
    BinaryTree* tmp;
    tmp = head;
    while (tmp != nullptr) {
        if(tmp->search(key, tmp->getRoot()) != nullptr) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return nullptr;
}

ds_course::Alien *ds_course::LinkedList::searchAlienInAllTrees(int key) {
    BinaryTree* tmp = head;
    Alien* tmpAlien;
    while (tmp != nullptr) {
        if((tmpAlien = tmp->search(key, tmp->getRoot())) != nullptr) {
            return tmpAlien;
        }
        tmp = tmp->next;
    }

    return nullptr;
}

void ds_course::LinkedList::displayAllTrees() {
//    std::cout << "Starting displaying ll" << std::endl;
    BinaryTree* tmp;
    tmp = head;
    while (tmp != nullptr) {
        tmp->displayTree();
        std::cout << std::endl;
        tmp = tmp->next;
    }
}

int ds_course::LinkedList::insertAlien(int parentKey, int childKey, char pos) {
    if (parentKey == childKey) {
        std::cout << "error1" << std::endl; // Parent and Child are the same.
        return -1;
    }

//    std::cout << "1" << std::endl;
    Alien* a = nullptr;
    if (parentKey > 0) {
        a = searchAlienInAllTrees(parentKey);
        if (a == nullptr) {
            std::cout << "error2" << std::endl; // Parent does not exist in any family tree.
            return -2;
        }
    }

//    std::cout << "2" << std::endl;
    bool childAlreadyExists = (searchAlienInAllTrees(childKey) != nullptr);
//    std::cout << "2.2" << std::endl;
    if (childAlreadyExists && pos != 'T') {
        std::cout << "error3" << std::endl; // Child is already used in some family tree.
        return -3;
    }

    if (a != nullptr) {
//    std::cout << "3" << std::endl;
        if (a->getLeft() != nullptr && pos == 'L') {
            std::cout << "error 4" << std::endl; // Parent already has a left-handed child in the family tree
            return -4;
        }
//    std::cout << "4" << std::endl;

        if (a->getRight() != nullptr && pos == 'R') {
            std::cout << "error 5" << std::endl; // Parent already has a right-handed child in the family tree
            return -5;
        }
    }
//    std::cout << "5" << std::endl;

    if (childAlreadyExists && pos == 'T') {
        std::cout << "error6" << std::endl; // Ancestor cannot start a new tree, since is already used in some family tree.
        return -6;
    }
//    std::cout << "6" << std::endl;

    switch (pos) {
        case 'L':
            a->setLeft(childKey);
            a->getLeft()->setParent(a);
            break;
        case 'R':
            a->setRight(childKey);
            a->getRight()->setParent(a);
            break;
        case 'T':
            addTree();
            tail->setRoot(childKey);
            tail->rootInserted = true;
            break;
        default:
            std::cout << "[ERROR] Not recognized command." << std::endl;
            exit(-1);
    }

    return 1;
}

void ds_course::LinkedList::inorderPrint(ds_course::Alien* root) {
    if (root != nullptr) {
        inorderPrint(root->getLeft());
        std::cout<<root->getNum()<<" ";
        inorderPrint(root->getRight());
    }
}

// function name not descriptive
void ds_course::LinkedList::inorder(ds_course::Alien *root, int* result, int previous) {
    ds_course::Alien* tmp;
    if (root->getLeft() == nullptr)
        if (root->getParent() != nullptr) {
            if (root->getParent()->getRight() != nullptr && root->getParent()->getRight()->getNum() == root->getNum())
                *result = root->getParent()->getNum();
            else
                *result = 0;
        } else {
            *result = 0;
        }
    else {
        tmp = root->getLeft();
        while (tmp->getRight() != nullptr) {
            tmp = tmp->getRight();
        }
        *result = tmp->getNum();
    }
}

// function name not descriptive
void ds_course::LinkedList::inorder2(ds_course::Alien *root, int* result, int previous) {
    ds_course::Alien* tmp;
    if (root->getRight() == nullptr) // no next
        if (root->getParent() != nullptr) {
            if (root->getParent()->getLeft() != nullptr && root->getParent()->getLeft()->getNum() == root->getNum())
                *result = root->getParent()->getNum();
            else
                *result = 0;
        } else {
            *result = 0;
        }
    else {
            tmp = root->getRight();
        while (tmp->getLeft() != nullptr) {
            tmp = tmp->getLeft();
        }
        *result = tmp->getNum();
    }
}

int ds_course::LinkedList::findFavorites(int key) {
    Alien* theAlien = searchAlienInAllTrees(key);
    if (theAlien == nullptr) {
        std::cout << "error0" << std::endl;
        return -1;
    }
    int preceding = -1;
    int next = -1;
    inorder(theAlien, &preceding, -1);
    inorder2(theAlien, &next, -1);
    std::cout << preceding << " " << next << std::endl;

    return 0;
}