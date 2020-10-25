#ifndef EX06_SHAPES_POLYGON_H
#define EX06_SHAPES_POLYGON_H

#include <Shape.h>
#include <Matrix.h>

namespace ds_course {
    class Polygon: public Shape {
    public:
        Polygon(std::string color, int n);
        ~Polygon();
        std::string draw(); // return SVG
        void transform(Matrix<double> m);
        Shape* clone();
    private:
        int n;
        std::string color;
        Matrix<double>** points;
    };
}


#endif //EX06_SHAPES_POLYGON_H
