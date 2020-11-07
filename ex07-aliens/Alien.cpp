#include "Alien.h"
#include "iostream"

ds_course::Alien::Alien(int nn) {
    num = nn;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

ds_course::Alien::~Alien() {

}

int ds_course::Alien::getNum() {
    return num;
}

ds_course::Alien* ds_course::Alien::getRight() {
    return right;
}

ds_course::Alien* ds_course::Alien::getLeft() {
    return left;
}

void ds_course::Alien::setRight(int key) {
    if (right == nullptr) {
        right = new Alien(key);
    } else {
//        std::cout << "[ERROR] Right already set!" << std::endl;
        std::cout << "error5" << std::endl; // Parent already has a right-handed child in the family tree.
        exit(-1);
    }
}

void ds_course::Alien::setLeft(int key) {
    if (left == nullptr) {
        left = new Alien(key);
    } else {
//        std::cout << "[ERROR] Left already set!" << std::endl;
        std::cout << "error4" << std::endl; // Parent already has a left-handed child in the family tree.
        exit(-1);
    }
}

ds_course::Alien *ds_course::Alien::getParent() {
    return parent;
}

void ds_course::Alien::setParent(Alien* al) {
    parent = al;
}
