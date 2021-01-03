#ifndef EX07_ALIENS_LINKEDLIST_H
#define EX07_ALIENS_LINKEDLIST_H

#include "BinaryTree.h"

namespace ds_course {
    class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        BinaryTree* addTree(); // creates new binary tree
        BinaryTree* searchTreeForKey(int key); // returns tree in which the key exist or nullptr
        void displayAllTrees(); // cout all elements (trees)
        int insertAlien(int parentKey, int childKey, char pos); // insert element
        Alien* searchAlienInAllTrees(int key);
        int findFavorites(int key);
        int inorder(ds_course::Alien *root, int *next, int previous);
        int inorder2(ds_course::Alien *root, int *next, int previous);
        void inorderPrint(ds_course::Alien *root);

    private:
        BinaryTree *head, *tail;

    };
}


#endif //EX07_ALIENS_LINKEDLIST_H
