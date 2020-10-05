#ifndef INC_2020_BITL_WORKSPACE_CPP_MATRIX_H
#define INC_2020_BITL_WORKSPACE_CPP_MATRIX_H

#include "Ratio.h"
#include <iostream>
#include <string>

namespace ds_course
{
    template <class T>
    class Matrix
    {
    private:
        int rows; // row count
        int cols; // column count
    public:
        T **a;
        Matrix(int rr, int cc);
        int getRows();
        int getCols();

        ds_course::Matrix<T> operator+(const ds_course::Matrix<T> &rhs);
        ds_course::Matrix<T> operator-(const ds_course::Matrix<T> &rhs);
        ds_course::Matrix<T> operator*(const ds_course::Matrix<T> &rhs);
        bool operator==(const ds_course::Matrix<T> &rhs);

        friend std::istream &operator>>(std::istream &input, ds_course::Matrix<T> &m)
        {
            for (int i = 0; i < m.getRows(); i++)
                for (int j = 0; j < m.getCols(); j++) {
                    input >> m.a[i][j];
                }
            return input;
        }

        friend std::ostream& operator<< (std::ostream& oStream, const Matrix<T> rhs) {
            oStream << rhs.rows << " " << rhs.cols << std::endl;

            for (int i = 0; i < rhs.rows; i++) {
                for (int j = 0; j < rhs.cols; j++) {
                    oStream << rhs.a[i][j];
                    if (j != rhs.cols - 1)
                        oStream << " ";
                }
                if (i != rhs.rows - 1)
                    oStream << std::endl;
            }


            return oStream;
        }
    };
} // namespace ds_course


template <class T>
ds_course::Matrix<T>::Matrix(int rr, int cc) : rows(rr), cols(cc)
{
    a = new T *[rows];
    for (int i = 0; i < rows; i++)
        a[i] = new T[cols];
}

template <class T>
int ds_course::Matrix<T>::getRows() { return rows; }

template <class T>
int ds_course::Matrix<T>::getCols() { return cols; }

template <class T>
ds_course::Matrix<T> ds_course::Matrix<T>::operator+(const ds_course::Matrix<T> &rhs) {
    if (rows != rhs.rows || cols != rhs.cols)
        throw std::out_of_range("Cannot add matrixes (num of rows/cols differs)!");

    Matrix<T> result_matrix(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            result_matrix.a[i][j] = a[i][j] + rhs.a[i][j];
        }

    return result_matrix;
}

template <class T>
ds_course::Matrix<T> ds_course::Matrix<T>::operator-(const ds_course::Matrix<T> &rhs) {
    if (rows != rhs.rows || cols != rhs.cols)
        throw std::out_of_range("Cannot add matrixes (num of rows/cols differs)!");

    Matrix<T> result_matrix(rows, cols);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            result_matrix.a[i][j] = a[i][j] * rhs.a[i][j];
        }

    return result_matrix;
}

template <class T>
ds_course::Matrix<T> ds_course::Matrix<T>::operator*(const ds_course::Matrix<T> &rhs) {
    if (cols != rhs.rows)
        throw std::out_of_range("Cannot do multiplication on matrixes (m1 cols != m2 rows)!");

    Matrix<T> result_matrix(rows, rhs.cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            result_matrix.a[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                result_matrix.a[i][j] = result_matrix.a[i][j] + (a[i][k] * rhs.a[k][j]);
//                std::cout << a[i][k] << "*" << rhs.a[k][j] << "=" << a[i][k]*rhs.a[k][j] << std::endl;
//                std::cout << "result_matrix.a[i][j]=" << result_matrix.a[i][j] << " ... + a[i][k] * rhs.a[k][j] (" << a[i][k]*rhs.a[k][j] << ")" << " ... === " << result_matrix.a[i][j] + (a[i][k] * rhs.a[k][j]) << std::endl;
            }
        }
    }

    return result_matrix;
}

template <class T>
bool ds_course::Matrix<T>::operator==(const ds_course::Matrix<T> &rhs)
{
    if (rows != rhs.rows)
        throw std::out_of_range("row counts differ");

    if (cols != rhs.cols)
        throw std::out_of_range("col counts differ");

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (!(a[i][j] == rhs.a[i][j])) {
                std::cout << a[i][j] << " != " << rhs.a[i][j] << std::endl;
                return false;
            }
    return true;
}



#endif //INC_2020_BITL_WORKSPACE_CPP_MATRIX_H
