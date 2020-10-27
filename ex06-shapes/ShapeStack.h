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
        bool iterHasNext();
        void iterReset();
        Shape* iterNext();
        Shape* shapes[1000];
    private:
        int _size;
        int iterCursor;
    };
}

#endif //EX06_SHAPES_SHAPESTACK_H
