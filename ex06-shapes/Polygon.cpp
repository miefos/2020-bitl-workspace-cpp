#include "Polygon.h"
#include "Transformation.h"
#include <cmath>
#include <sstream>
#include <utility>

ds_course::Polygon::Polygon(std::string color, int n) {
    this->color = std::move(color);
    this->type = "Polygon";
    this->n = n;
    double angle = 2*M_PI/n;

    for (int i = 0; i < n; i++) {
        double x = cos(i * angle);
        double y = sin(i * angle);
        points[i] = new Matrix<double>(1, 2);
        points[i]->a[0][0] = x;
        points[i]->a[0][1] = y;
    }
}

ds_course::Polygon::~Polygon() {

}

ds_course::Shape *ds_course::Polygon::clone() {
    Shape* new_shape = new Polygon(color, n);
    for (int i = 0; i < n; i++) {
        new_shape->points[i]->a[0][0] = points[i]->a[0][0];
        new_shape->points[i]->a[0][1] = points[i]->a[0][1];
    }
    new_shape->type = type;

    return new_shape;
}
