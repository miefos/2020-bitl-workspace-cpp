#include "Group.h"

#include <ShapeStack.h>
#include <Matrix.h>

ds_course::Group::Group(ds_course::ShapeStack stack) {

}

ds_course::Group::~Group() {

}

std::string ds_course::Group::draw() {
    return std::string();
}

void ds_course::Group::transform(ds_course::Matrix<double> m) {

}

ds_course::Shape *ds_course::Group::clone() {
    return nullptr;
}