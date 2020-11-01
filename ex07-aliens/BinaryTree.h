#ifndef INC_2020_BITL_WORKSPACE_CPP_BINARYTREE_H
#define INC_2020_BITL_WORKSPACE_CPP_BINARYTREE_H

#include <iostream>
#include <Alien.h>

namespace ds_course {
    class BinaryTree {
    public:
        BinaryTree();
        ~BinaryTree();

        void insert(int key); // also validates that can be inserted
        Alien *search(int key); // returns nullptr if no exist
        void merge_trees(BinaryTree* bt);
        void destroy_tree();
        std::string getFavRelatives(int key);

    private:
        Alien *root;
    };
}


#endif //INC_2020_BITL_WORKSPACE_CPP_BINARYTREE_H
