#ifndef INC_2020_BITL_WORKSPACE_CPP_BINARYTREE_H
#define INC_2020_BITL_WORKSPACE_CPP_BINARYTREE_H

#include <iostream>
#include <Alien.h>

namespace ds_course {
    class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();

        bool rootInserted;
        BinaryTree* next;

//        void insert(int parent, int key, char pos);
        Alien *search(int key, Alien* current); // returns nullptr if no exist
        void merge_trees(BinaryTree* bt);
        void destroy_tree();
        std::string getFavRelatives(int key);
        void displayTree();
        Alien* getRoot();
        void setRoot(int nn);

    private:
        Alien *root;
    };
}


#endif //INC_2020_BITL_WORKSPACE_CPP_BINARYTREE_H
