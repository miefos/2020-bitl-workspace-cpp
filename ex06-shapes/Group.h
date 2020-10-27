#ifndef EX06_SHAPES_GROUP_H
#define EX06_SHAPES_GROUP_H

#include <ShapeStack.h>
#include <Matrix.h>
#include <Shape.h>
#include <iostream>

namespace ds_course {
    class Group: public Shape {
    private:
        ShapeStack stack;
    public:
        Group(ShapeStack stack);
        ~Group();
        std::string draw(); // output SVG
        void transform(Matrix<double> m);
        Shape* clone();
    };
}

#endif //EX06_SHAPES_GROUP_H
