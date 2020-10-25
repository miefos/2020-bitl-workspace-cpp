#include "Circle.h"


ds_course::Circle::Circle(std::string color) {
    std::cout << "Circle created!" << std::endl;
}

ds_course::Circle::~Circle() {

}

std::string ds_course::Circle::draw() {
    return std::string();
}

void ds_course::Circle::transform(ds_course::Matrix<double> m) {

}

ds_course::Shape *ds_course::Circle::clone() {
    return nullptr;
}
