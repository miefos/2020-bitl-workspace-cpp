#ifndef EX06_SHAPES_SHAPESTACK_H
#define EX06_SHAPES_SHAPESTACK_H

#include <Shape.h>

namespace ds_course {
    class ShapeStack {
    public:
        ShapeStack();
        ~ShapeStack();
        int size();
        bool empty();
        Shape* top();
        void push(Shape* sh);
        void pop();
    private:
        int top_elem;
        Shape* shapes[1000];
        int iterCursor;
        void iterReset();
        bool iterHasNext();
        Shape* iterNext();
    };
}

#endif //EX06_SHAPES_SHAPESTACK_H
