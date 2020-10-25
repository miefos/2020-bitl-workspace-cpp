#ifndef EX06_SHAPES_CIRCLE_H
#define EX06_SHAPES_CIRCLE_H

#include <Shape.h>
#include <Matrix.h>

namespace ds_course {
    class Circle: public Shape {
    public:
        Circle(std::string color);
        ~Circle();
        std::string draw(); // return SVG
        void transform(Matrix<double> m);
        Shape* clone();
    private:
        int n;
        std::string color;
        Matrix<double>** points;
    };
}


#endif //EX06_SHAPES_CIRCLE_H
