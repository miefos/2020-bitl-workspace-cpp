#include "ShapeStack.h"

#define MC_MAX_SHAPES 1000

using namespace std;

namespace ds_course {

    ShapeStack::ShapeStack() {
        _size = 0;
        iterCursor = 0;
    }

    ShapeStack::~ShapeStack() {

    }

    int ShapeStack::size() {
        return _size;
    }

    bool ShapeStack::empty() {
        return size() > 0;
    }

    Shape *ShapeStack::top() {
        if (_size-1 < 0)
            return nullptr;
        return shapes[_size-1];
    }

    void ShapeStack::push(Shape *sh) {
//        cout << "COL received in push " << sh->color << endl;
        shapes[_size] = sh;
//        cout << "COL assigned in push " << shapes[_size+1]->color << endl;
        _size++;
    }

    void ShapeStack::pop() {
        if (_size - 1 >= 0) {
            shapes[_size - 1] = nullptr;
            _size--;
        }
    }

    void ShapeStack::iterReset() {
        iterCursor = 0;
    }

    bool ShapeStack::iterHasNext() {
        if (iterCursor < MC_MAX_SHAPES)
            if (shapes[iterCursor] != nullptr)
                return true;
        return false;
    }

    Shape *ShapeStack::iterNext() {
        if (iterHasNext()) {
            iterCursor++;
            return shapes[iterCursor-1];
        }
        return nullptr;
    }
}