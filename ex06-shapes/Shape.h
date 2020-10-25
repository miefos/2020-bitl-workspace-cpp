#ifndef EX06_SHAPES_SHAPE_H
#define EX06_SHAPES_SHAPE_H

#include <string>
#include <Matrix.h>

// Shape is purely virtual
namespace ds_course {
    class Shape {
    public:
        virtual std::string draw() = 0; // output SVG
        virtual void transform(Matrix<double> m) = 0;
        virtual Shape* clone() = 0;
    };
}

#endif //EX06_SHAPES_SHAPE_H
