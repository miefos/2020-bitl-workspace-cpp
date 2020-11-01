#ifndef EX07_ALIENS_LINKEDLIST_H
#define EX07_ALIENS_LINKEDLIST_H

#include <BinaryTree.h>

namespace ds_course {
    class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        BinaryTree* addTree(); // creates new binary tree
        BinaryTree* searchTreeForKey(int key); // returns tree in which the key exist or nullptr

    private:
        BinaryTree *head, *tail;

    };
}


#endif //EX07_ALIENS_LINKEDLIST_H
