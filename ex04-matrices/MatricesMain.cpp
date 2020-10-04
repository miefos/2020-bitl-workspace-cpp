#include <iostream>
#include "Matrix.h"
#include "Ratio.h"

// Run g++ MatricesMain.cpp -o main.exe

using namespace ds_course;
using namespace std;

int main() {
    Ratio r1(-17,-34);
    Ratio r2(1,3);
    cout << r1 << endl;
    cout << r2 << endl;
    cout << (r1 + r2) << endl;

    Matrix<Ratio> m1(2,2);
    Matrix<Ratio> m2(2,2);
    cin >> m1 >> m2;
    cout << "(m1 == m2) is " << ((m1 == m2)? "true" : "false" ) << endl;
    cout << "m2.a[1][1] = " << m2.a[1][1] << endl;

    return 0;
}