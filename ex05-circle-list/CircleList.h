#ifndef INC_2020_BITL_WORKSPACE_CPP_CIRCLELIST_H
#define INC_2020_BITL_WORKSPACE_CPP_CIRCLELIST_H

#include "CNode.h"
#include <string>

namespace ds_course {
    class CircleList {
    private:
        CNode *cursor;
        int size;

    public:
        explicit CircleList();
        ~CircleList();
        bool empty();
        const int &front() const;
        const int &back() const;
        void add(const int &e);
        void remove();
        void advance();
        void retreat();
        int getSize();
        std::string to_str() const;

    };
}


#endif //INC_2020_BITL_WORKSPACE_CPP_CIRCLELIST_H
