#include <iostream>
#include "Matrix.h"
#include "Ratio.h"

// Run g++ MatricesMain.cpp -o main.exe

using namespace ds_course;
using namespace std;

int main() {
    try {
        string mode1, mode2; // MR - float, MZ - integers, MQ - ratio
        int m1, n1, m2, n2; // rows, cols

        // Insert matrix 1
        cin >> mode1 >> m1 >> n1;

        Matrix<int> matrix1int(m1, n1);
        Matrix<Ratio> matrix1ratio(m1, n1);
        Matrix<float> matrix1float(m1, n1);

        if (mode1 == "MZ") {
            cin >> matrix1int;
        } else if (mode1 == "MQ") {
            cin >> matrix1ratio;
        } else if (mode1 == "MR") {
            cin >> matrix1float;
        } else {
            throw std::out_of_range("Invalid matrix type!");
        }

        // Insert matrix 2
        cin >> mode2 >> m2 >> n2;

        if (mode1 != mode2)
            throw std::out_of_range("Matrix types should match!");

        Matrix<int> matrix2int(m2, n2);
        Matrix<Ratio> matrix2ratio(m2, n2);
        Matrix<float> matrix2float(m2, n2);

        if (mode2 == "MZ") {
            cin >> matrix2int;
        } else if (mode2 == "MQ") {
            cin >> matrix2ratio;
        } else if (mode2 == "MR") {
            cin >> matrix2float;
        } else {
            throw std::out_of_range("Invalid matrix type!");
        }

        string operation;
        cin >> operation;

        // ADD
        if (operation == "ADD") {
            if (mode1 == "MZ") { // int
                Matrix<int> result_matrix(m1, n1);
                result_matrix = matrix1int + matrix2int;
                cout << mode1 << " " << result_matrix;
            } else if (mode1 == "MQ") { // ratio
                Matrix<Ratio> result_matrix(m1, n1);
                result_matrix = matrix1ratio + matrix2ratio;
                cout << mode1 << " " << result_matrix;
            } else if (mode1 == "MR") { // float
                Matrix<float> result_matrix(m1, n1);
                result_matrix = matrix1float + matrix2float;
                cout << mode1 << " " << result_matrix;
            }
        // SUB
        } else if (operation == "SUB") {
            if (mode1 == "MZ") { // int
                Matrix<int> result_matrix(m1, n1);
                result_matrix = matrix1int - matrix2int;
                cout << mode1 << " " << result_matrix;
            } else if (mode1 == "MQ") { // ratio
                Matrix<Ratio> result_matrix(m1, n1);
                result_matrix = matrix1ratio - matrix2ratio;
                cout << mode1 << " " << result_matrix;
            } else if (mode1 == "MR") { // float
                Matrix<float> result_matrix(m1, n1);
                result_matrix = matrix1float - matrix2float;
                cout << mode1 << " " << result_matrix;
            }
        // MUL
        } else if (operation == "MUL") {
            if (mode1 == "MZ") { // int
                Matrix<int> result_matrix(m1, n2);
                result_matrix = matrix1int * matrix2int;
                cout << mode1 << " " << result_matrix;
            } else if (mode1 == "MQ") { // ratio
                Matrix<Ratio> result_matrix(m1, n2);
                result_matrix = matrix1ratio * matrix2ratio;
                cout << mode1 << " " << result_matrix;
            } else if (mode1 == "MR") { // float
                Matrix<float> result_matrix(m1, n2);
                result_matrix = matrix1float * matrix2float;
                cout << mode1 << " " << result_matrix;
            }
        } else {
            throw std::out_of_range("Invalid operation!");
        }

//        cout << endl;
    } catch (const out_of_range& oor) {
        cout << "out_of_range" << oor.what();
    }

    return 0;
}