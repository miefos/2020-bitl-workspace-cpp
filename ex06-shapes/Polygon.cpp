#include "Polygon.h"


ds_course::Polygon::Polygon(std::string color, int n) {
    std::cout << "Polygon created!" << std::endl;
}

ds_course::Polygon::~Polygon() {

}

std::string ds_course::Polygon::draw() {
    return std::string();
}

void ds_course::Polygon::transform(ds_course::Matrix<double> m) {

}

ds_course::Shape *ds_course::Polygon::clone() {
    return nullptr;
}
