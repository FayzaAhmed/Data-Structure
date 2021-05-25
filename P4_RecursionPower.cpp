// P4_RecursionPower.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;

int power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return  a * power(a, n - 1);
}


int power1(int a, int n)
{
    if (n % 2 != 0) 
    {
        return  power(a, n / 2) * power(a, (n / 2) + 1);
    }
    else    
    {
        return   power1(a, n / 2) * power1(a, n / 2); 
    }
}

int main()
{
    cout << "Input : 2 3 \nOutput : " << power(2, 3) << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Input : 3 2 \nOutput : " << power1(3, 2) << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Input : 2 4 \nOutput : " << power1(2, 4) << endl;
}


