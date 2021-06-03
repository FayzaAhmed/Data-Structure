#pragma once
#include <iostream>

using namespace std;

template <class T>

class Matrix
{
private:
    int rows, cols;
    T** data;                                  //two dimensional matrix
public:
    Matrix(int rows, int cols);              //parametrized constructor
    Matrix(const Matrix& otherMatrix);        //copy constructor
    ~Matrix();                                //Destructor
    void print();                             //prints the matrix data
    void matrixTranspose();                   //gets the transpose of the matrix

    Matrix operator+ (const Matrix& obj);     //overloading the operator+
    Matrix operator- (const Matrix& obj);     //overloading the operator-
    Matrix operator* (const Matrix& obj);     //overloading the operator*

    friend istream& operator>>  (istream& in, Matrix<T>& obj)
    {
        for (int i = 0; i < obj.rows; i++)
        {
            for (int j = 0; j < obj.cols; j++)
                in >> obj.data[i][j];
        }
        return in;
    }

    friend ostream& operator<< (ostream& out, const Matrix<T>& obj)
    {
        for (int i = 0; i < obj.rows; i++)
        {
            for (int j = 0; j < obj.cols; j++)
                out << obj.data[i][j] << " ";

            out << endl;
        }
        return out;
    }


};