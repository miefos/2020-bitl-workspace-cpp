#ifndef EX06_SHAPES_SHAPE_H
#define EX06_SHAPES_SHAPE_H

#include <string>
#include <Matrix.h>
#include <Transformation.h>

// Shape is purely virtual
namespace ds_course {
    class Shape {
    public:
        virtual std::string draw() {
            return Transformation::getDrawing(n, color, points);
        }; // output SVG
        virtual void transform(Matrix<double> m) {
            // loop throuh all points
            for (int i = 0; i < n; i++) {
                Matrix<double> vv(3,1); // column vector has 3 rows, 1 column
                vv.a[0][0] = points[i]->a[0][0]; // old x
                vv.a[1][0] = points[i]->a[0][1]; // old y
                vv.a[2][0] = 1; // always 1
                Matrix<double> ww = m*vv;
                double new_x = ww.a[0][0];
                double new_y = ww.a[1][0];
                points[i]->a[0][0] = new_x;
                points[i]->a[0][1] = new_y;
            }
        };
        virtual Shape* clone() = 0;
        int n;
        std::string type;
        std::string color;
        Matrix<double>* points[1000];

    };
}

#endif //EX06_SHAPES_SHAPE_H
