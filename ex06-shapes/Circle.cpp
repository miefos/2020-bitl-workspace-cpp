#include "Circle.h"
#include "Transformation.h"
#include <cmath>
#include <sstream>
#include <utility>

ds_course::Circle::Circle(std::string color) {
    this->color = std::move(color);
    this->n = 1000;
    double angle = 2*M_PI/n;

    for (int i = 0; i < n; i++) {
        double x = cos(i * angle);
        double y = sin(i * angle);
        points[i] = new Matrix<double>(1, 2);
        points[i]->a[0][0] = x;
        points[i]->a[0][1] = y;
    }
}

ds_course::Circle::~Circle() {

}

std::string ds_course::Circle::draw() {
    return Transformation::getDrawing(n, color, points);
}

void ds_course::Circle::transform(ds_course::Matrix<double> m) {

}

ds_course::Shape *ds_course::Circle::clone() {
    return nullptr;
}
