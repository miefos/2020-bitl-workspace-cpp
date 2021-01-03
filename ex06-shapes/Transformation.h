#ifndef EX06_SHAPES_TRANSFORMATION_H
#define EX06_SHAPES_TRANSFORMATION_H

#include "Matrix.h"
#include <cmath>
#include <sstream>
#ifndef M_PI
    #define M_PI acos(-1.0)
#endif
namespace ds_course {
    class Transformation {
    public:
        static Matrix<double> getTRA(double dx, double dy) {
            Matrix<double> matrix(3, 3);
            // new row
            matrix.a[0][0] = 1;
            matrix.a[0][1] = 0;
            matrix.a[0][2] = dx;
            // new row
            matrix.a[1][0] = 0;
            matrix.a[1][1] = 1;
            matrix.a[1][2] = dy;
            // new row
            matrix.a[2][0] = 0;
            matrix.a[2][1] = 0;
            matrix.a[2][2] = 1;

            return matrix;
        }

        static Matrix<double> getROT(double angle) {
            Matrix<double> matrix(3, 3);
            // new row
            matrix.a[0][0] = cos(angle);
            matrix.a[0][1] = -sin(angle);
            matrix.a[0][2] = 0;
            // new row
            matrix.a[1][0] = sin(angle);
            matrix.a[1][1] = cos(angle);
            matrix.a[1][2] = 0;
            // new row
            matrix.a[2][0] = 0;
            matrix.a[2][1] = 0;
            matrix.a[2][2] = 1;

            return matrix;
        }

        static Matrix<double> getSCA(double cx, double cy) {
            Matrix<double> matrix(3, 3);
            // new row
            matrix.a[0][0] = cx;
            matrix.a[0][1] = 0;
            matrix.a[0][2] = 0;
            // new row
            matrix.a[1][0] = 0;
            matrix.a[1][1] = cy;
            matrix.a[1][2] = 0;
            // new row
            matrix.a[2][0] = 0;
            matrix.a[2][1] = 0;
            matrix.a[2][2] = 1;

            return matrix;
        }

        static Matrix<double> getSHA(double cx, double cy) {
            Matrix<double> matrix(3, 3);
            // new row
            matrix.a[0][0] = 1;
            matrix.a[0][1] = cx;
            matrix.a[0][2] = 0;
            // new row
            matrix.a[1][0] = cy;
            matrix.a[1][1] = 1;
            matrix.a[1][2] = 0;
            // new row
            matrix.a[2][0] = 0;
            matrix.a[2][1] = 0;
            matrix.a[2][2] = 1;

            return matrix;
        }

        static std::string getDrawing(int n, std::string color, Matrix<double>** points) {
            std::string svg_string;
            svg_string = "<path d=\"";
            bool first = true;

            for (int k = 0; k < n; k++) {
                if (points[k]->getRows() != 1 || points[k]->getCols() != 2) {
                    return ""; // error
                }
                for (int i = 0; i < points[k]->getRows(); i++) {
                    if (first) {
                        svg_string += "M ";
                        first = false;
                    } else {
                        svg_string += "L ";
                    }
                    for (int j = 0; j < points[k]->getCols(); j++) {
                        std::stringstream tmp;
                        tmp << std::fixed << std::setprecision(5) << points[k]->a[i][j];
                        svg_string += tmp.str();
                        tmp.str(std::string());
                        svg_string += " ";
                    }
                }
            }
            svg_string += "\" fill=\"";
            svg_string += color;
            svg_string += "\"/>";

            return svg_string;
        }
    };
}

#endif //EX06_SHAPES_TRANSFORMATION_H
