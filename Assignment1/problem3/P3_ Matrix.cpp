// P3_ Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"

class  MatrixCalculator
{
public:
    void menu()
    {
        int rows, cols;

        cout << "1- Perform Matrix Addition \n2- Perform Matrix Subtraction \n3- Perform Matrix Multiplication \n4- Matrix Transpose\n";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:    //addition
        {
            cout << "Enter the number of rows and cols of the first matrix respectively\n";
            cin >> rows >> cols;
            cout << endl;

            Matrix <int> matrix1(rows, cols);
            cin >> matrix1;
            cout << endl;

            cout << "Enter the number of rows and cols of the second matrix respectively\n";
            cin >> rows >> cols;
            cout << endl;

            Matrix <int> matrix2(rows, cols);
            cin >> matrix2;
            cout << endl;

            Matrix <int> result(matrix1 + matrix2);

            cout << result;
            break;
        }
        case 2:    //subtraction
        {
            cout << "Enter the number of rows and cols of the first matrix respectively\n";
            cin >> rows >> cols;
            cout << endl;

            Matrix <int> matrix1(rows, cols);
            cin >> matrix1;
            cout << endl;

            cout << "Enter the number of rows and cols of the second matrix respectively\n";
            cin >> rows >> cols;
            cout << endl;

            Matrix <int> matrix2(rows, cols);
            cin >> matrix2;
            cout << endl;

            Matrix <int> result(matrix1 - matrix2);

            cout << result;

            break;
        }

        case 3:     //multiplication
        {
            cout << "Enter the number of rows and cols of the first matrix respectively\n";
            cin >> rows >> cols;
            cout << endl;

            Matrix <int> matrix1(rows, cols);
            cin >> matrix1;
            cout << endl;

            cout << "Enter the number of rows and cols of the second matrix respectively\n";
            cin >> rows >> cols;
            cout << endl;

            Matrix <int> matrix2(rows, cols);
            cin >> matrix2;
            cout << endl;

            Matrix <int> result(matrix1 * matrix2);

            cout << result;
            break;
        }
        case 4:      //transpose
        {
            cout << "Enter the number of rows and cols of the first matrix respectively\n";
            cin >> rows >> cols;
            cout << endl;

            Matrix <int> matrix1(rows, cols);
            cin >> matrix1;
            cout << endl;
            matrix1.matrixTranspose();

            break;
        }
        default:
        {
            cout << "invalid input \n";
            break;
        }

        }

    }
};
using namespace std;

int main()
{


    cout << " Welcome to FCI Matrix Calculator \n";
    cout << " -------------------------------------- \n";
    MatrixCalculator m;
    m.menu();




    return 0;
}