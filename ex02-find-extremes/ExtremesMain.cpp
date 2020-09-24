#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include "Student.h"

using namespace std;
using namespace ds_course;

namespace ds_course {
// return the smallest student object in the array ss[count]
    Student getMin(Student *ss, int count);

// return the largest student object in the array ss[count]
    Student getMax(Student *ss, int count);
}

int main()
{
    string inputLine;
    int N;
    cin >> N;
    // create an array of students with number of elements N
    // the same as Student* ss = new Student[N] or Student ss[N];
    auto* ss = new Student[N];

    cin.ignore(10000,'\n');

    for (int i = 0; i < N; i++) {
        getline(cin, inputLine);

        // split by whitespace (explode function)
        std::vector<std::string> result;

        std::istringstream iss(inputLine);
        for(std::string s; iss >> s; )
            result.push_back(s);

        // check if two elements in array
        if (result.size() != 2) {
            cout << "There was error with input data." << endl;
            return 1;
        }

        // set age and height of student
        Student* st = &(ss[i]);
        st->age = stoi(result.at(0));
        st->height = stod(result.at(1));

        // print age and height
//        printf("Student is %d years old and has height of %fm.\n", st->age, st->height);
    }

    Student minStudent = getMin(ss, N);
    Student maxStudent = getMax(ss, N);
    cout << minStudent.age << " " << std::fixed << std::setprecision(5) << minStudent.height << endl;
    cout << maxStudent.age << " " << std::fixed << std::setprecision(5) << maxStudent.height << endl;

    return 0;
}



namespace ds_course {
// return the smallest student object in the array ss[count]
    Student getMin(Student *ss, int count) {
        Student* minStudent = &(ss[0]);

        for (int i = 0; i < count; i++) {
            if (minStudent->compareTo(ss[i]) == 1)
                minStudent = &(ss[i]);
        }
        return *minStudent;
    }

// return the largest student object in the array ss[count]
    Student getMax(Student *ss, int count) {
        Student* maxStudent = &(ss[0]);

        for (int i = 0; i < count; i++) {
            if (maxStudent->compareTo(ss[i]) == -1)
                maxStudent = &(ss[i]);
        }
        return *maxStudent;
    }
}