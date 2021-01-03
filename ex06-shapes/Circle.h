#ifndef EX06_SHAPES_CIRCLE_H
#define EX06_SHAPES_CIRCLE_H

#include "Shape.h"
#include "Matrix.h"

namespace ds_course {
    class Circle: public Shape {
    public:
        Circle(std::string color);
        ~Circle();
        Shape* clone();
    };
}


#endif //EX06_SHAPES_CIRCLE_H
