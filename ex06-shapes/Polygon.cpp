#include "Polygon.h"
#include "Transformation.h"
#include <cmath>
#include <sstream>
#include <utility>

ds_course::Polygon::Polygon(std::string color, int n) {
    this->color = std::move(color);
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

std::string ds_course::Polygon::draw() {
    return Transformation::getDrawing(n, color, points);
}

void ds_course::Polygon::transform(ds_course::Matrix<double> m) {

}

ds_course::Shape *ds_course::Polygon::clone() {
    return nullptr;
}
