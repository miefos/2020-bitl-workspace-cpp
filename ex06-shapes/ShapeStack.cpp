#include "ShapeStack.h"

#define MC_MAX_SHAPES 1000

namespace ds_course {

    ShapeStack::ShapeStack() {
        top_elem = 0;
        iterCursor = 0;
    }

    ShapeStack::~ShapeStack() {

    }

    int ShapeStack::size() {
        return top_elem;
    }

    bool ShapeStack::empty() {
        return size() > 0;
    }

    Shape *ShapeStack::top() {
        return shapes[top_elem];
    }

    void ShapeStack::push(Shape *sh) {
        shapes[top_elem+1] = sh;
        top_elem++;
    }

    void ShapeStack::pop() {
        shapes[top_elem] = nullptr;
        top_elem--;
    }

    void ShapeStack::iterReset() {
        iterCursor = 0;
    }

    bool ShapeStack::iterHasNext() {
        if (iterCursor + 1 < MC_MAX_SHAPES)
            if (shapes[iterCursor + 1] != nullptr)
                return true;
        return false;
    }

    Shape *ShapeStack::iterNext() {
        if (iterHasNext()) {
            iterCursor++;
            return shapes[iterCursor];
        }
        return nullptr;
    }
}