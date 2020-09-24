#include "Student.h"
#include <iostream>

using namespace ds_course;
using namespace std;

Student::Student() {} // empty constructor

int Student::compareTo(Student ss) {
//    cout << "Comparing " << endl;
//    cout << "Student 'this' with age " << this->age << " and height " << this->height << endl;
//    cout << "Student 'argument' with age " << ss.age << " and height " << ss.height << endl;

    // "this" student is older/taller
    if (this->age > ss.age || (this->age == ss.age && this->height > ss.height)) {
        return 1;
    // "argument" student is older/taller
    } else if (this->age < ss.age || (this->age == ss.age && this->height < ss.height)) {
        return -1;
    }
    // if age and height are equals
    return 0;
}