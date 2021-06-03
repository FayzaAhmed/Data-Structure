#include "Matrix.h"
#include <iostream>

using namespace std;
template < class T >

Matrix<T>::Matrix(int rows, int cols)  //parametrized constructor that takes the number of rows and cols and
{
    this->rows = rows;
    this->cols = cols;
    data = new T * [rows];

    for (int i = 0; i < rows; i++)
        data[i] = new T[cols];

}

template <class T>
Matrix<T>::Matrix(const Matrix& otherMatrix)      //copy constructor
{
    rows = otherMatrix.rows;
    cols = otherMatrix.cols;
    data = new T * [rows];

    for (int i = 0; i < rows; i++)
        data[i] = new T[cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            data[i][j] = otherMatrix.data[i][j];
    }
}



template <class T>
Matrix<T>::~Matrix()          //a destructor that frees the dynamic memory
{
    for (int i = 0; i < rows; i++)
        delete[] data[i];

    delete[] data;
}



template <class T>
void Matrix<T>::print()        // prints the data inside the Matrix
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << data[i][j] << " ";

        cout << endl;
    }
}



template <class T>
void Matrix<T>::matrixTranspose()      // gets the transpose of the matrix;
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << data[j][i] << " ";

        cout << endl;
    }
}



template <class T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T>& obj)    // overloading the operator +
{
    Matrix result(rows, cols);
    if (rows == obj.rows && cols == obj.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + obj.data[i][j];
        }
    }
    else
    {
        cout << "invalid addition" << endl;
        for (int i = 0; i < result.rows; i++)
        {
            for (int j = 0; j < result.cols; j++)
                result.data[i][j] = NULL;
        }
    }
    return result;
}






template <class T>
Matrix<T> Matrix<T>::operator- (const Matrix<T>& obj)      //overloading the operator -
{
    Matrix result(rows, cols);
    if (rows == obj.rows && cols == obj.cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] - obj.data[i][j];
        }
    }
    else
    {
        cout << "invalid subtraction" << endl;
        for (int i = 0; i < result.rows; i++)
        {
            for (int j = 0; j < result.cols; j++)
                result.data[i][j] = NULL;
        }
    }
    return result;
}




template <class T>
Matrix<T> Matrix<T>::operator* (const Matrix<T>& obj)       // overloading the operator *  to multiply two matrices
{
    Matrix result(rows, obj.cols);
    if (cols == obj.rows)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < obj.cols; j++)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * obj.data[k][j];
            }
        }
    }
    else
    {
        cout << "invalid multiplication";
        for (int i = 0; i < result.rows; i++)
        {
            for (int j = 0; j < result.cols; j++)
                result.data[i][j] = NULL;
        }
    }
    return result;
}