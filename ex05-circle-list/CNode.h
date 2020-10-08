#ifndef INC_2020_BITL_WORKSPACE_CPP_CNODE_H
#define INC_2020_BITL_WORKSPACE_CPP_CNODE_H

namespace ds_course {
    class CNode {
    private:
        int elem;
        CNode* next;
        CNode* prev;

    friend class CircleList;

    };

}


#endif //INC_2020_BITL_WORKSPACE_CPP_CNODE_H
