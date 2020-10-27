#include "Group.h"

#include <ShapeStack.h>
#include <Matrix.h>

using namespace std;

ds_course::Group::Group(ds_course::ShapeStack old_stack) {
    this->type = "Group";
//    cout << "old stack size: " << old_stack.size() << endl;
    for (int i = 0; i < old_stack.size(); i++) {
        Shape *copied = old_stack.iterNext();
//        cout << "COL" << copied->color << endl;
        stack.push(copied);

    }
//    cout << "new stack size: " << stack.size() << endl;
    old_stack.iterReset();
    stack.iterReset();
}

ds_course::Group::~Group() {

}

std::string ds_course::Group::draw() {
    std::string group_svg;
    ShapeStack tempStack;

    for (int i = 0; i < stack.size(); i++) {
        Shape* nextShape;
        if ((nextShape = stack.shapes[i]) == nullptr) {
            std::cout << "[ERROR] iter next..." << std::endl;
            return "";
        }
//        std::cout << "Shape type " << nextShape->type << std::endl;
        tempStack.push(nextShape);
    }

    for (int i = tempStack.size(); i > 0; i--) {
        group_svg += tempStack.shapes[i-1]->draw();
        group_svg += "\n";
    }
    stack.iterReset();

    return group_svg;
}

void ds_course::Group::transform(ds_course::Matrix<double> m) {
    for (int i = 0; i < stack.size(); i++) {
        stack.shapes[i]->transform(m);
    }
    stack.iterReset();
}

ds_course::Shape *ds_course::Group::clone() {
    ShapeStack new_stack;
    for (int i = 0; i < stack.size(); i++) {
        new_stack.push(stack.shapes[i]->clone());
    }

    return new Group(new_stack);
}