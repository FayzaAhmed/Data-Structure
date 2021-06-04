// A1_P6_20190376_20190101.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<iostream>
#include "StudentName.h"
using namespace std;

int main()
{
    StudentName s1("Osama Ahmed");
    s1.Replace(3, 1);                                       //test case 1
    s1.print();

    cout << "//////////////////////////////////////////////////\n\n";

    StudentName s2("Osama Ahmed");
    s2.Replace(4, 1);                                      //test case 2
    s2.print();

    cout << "//////////////////////////////////////////////////\n\n";

    StudentName s3("Fayroz is smartt");
    s3.Replace(3, 1);                                      //test case 3
    s3.print();

    cout << "//////////////////////////////////////////////////\n\n";

    StudentName s4("Ibrahim");
    s4.Replace(4, 5);                                      //test case 4
    s4.print();

    cout << "//////////////////////////////////////////////////\n\n";

    StudentName s5("Asmaa did great job");
    s5.Replace(3, 1);                                      //test case 5
    s5.print();

    cout << "//////////////////////////////////////////////////\n\n";

    return 0;
}