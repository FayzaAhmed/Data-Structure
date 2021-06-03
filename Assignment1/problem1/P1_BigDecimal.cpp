// P1_BigDecimal.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <sstream>
#include "BigDecimalInt.h"
using namespace std;
int main()
{
    while (true) {
        cout << "Welcome to FCI Calculator" << endl;
        cout << "--------------------------" << endl;
        cout << "1- Perform Addition" << endl << "2- Perform Subtraction" << endl << "3- Exit" << endl;
        int n;
        string s;
        cin >> n;
        if (n == 1) {

            // Test 1

            s = "123456789012345678901234567890";
            BigDecimalInt num1(s);
            cout << "num1 = " << num1 << endl;
            s = "113456789011345678901134567890";
            BigDecimalInt num2(s);
            cout << "num2 = " << num2 << endl;
            cout << "num1 + num2 = " << num1 + num2 << endl << endl;

            ///////////////////////////////////////////////

            // Test 2

            s = "-12345678901237890";
            num1.setdecStr(s);
            cout << "num1 = " << num1 << endl;
            s = "-113456789014567890";
            num2.setdecStr(s);
            cout << "num2 = " << num2 << endl;
            cout << "num1 + num2 = " << num1 + num2 << endl << endl;

            //////////////////////////////////////////////

            // Test 3

            s = "-100000000000000";
            num1.setdecStr(s);
            cout << "num1 = " << num1 << endl;
            s = "200000000000000";
            num2.setdecStr(s);
            cout << "num2 = " << num2 << endl;
            cout << "num1 + num2 = " << num1 + num2 << endl << endl;

            /////////////////////////////////////////////

            // Test 4

            s = "555555555555551";
            num1.setdecStr(s);
            cout << "num1 = " << num1 << endl;
            s = "-88776655441123";
            num2.setdecStr(s);
            cout << "num2 = " << num2 << endl;
            cout << "num1 + num2 = " << num1 + num2 << endl << endl;

            //////////////////////////////////////////////

            //Test 5

            s = "123456789012345678901234567890159753";
            num1.setdecStr(s);
            cout << "num1 = " << num1 << endl;
            s = "113456789011345678901134567890357951";
            num2.setdecStr(s);
            cout << "num2 = " << num2 << endl;
            cout << "num1 + num2 = " << num1 + num2 << endl << endl;


        }
        else if (n == 2) {

            // Test 1

            s = "1230000000000000001";
            BigDecimalInt num1(s);
            cout << "num1 = " << num1 << endl;
            s = "30000000000000001";
            BigDecimalInt num2(s);
            cout << "num2 = " << num2 << endl;
            cout << "num1 - num2 = " << num1 - num2 << endl << endl;

            //////////////////////////////////////////////

            // Test 2

            s = "-10000000000001";
            num1.setdecStr(s);
            cout << "num1 = " << num1 << endl;
            s = "-20000000000031";
            num2.setdecStr(s);
            cout << "num2 = " << num2 << endl;
            cout << "num1 - num2 = " << num1 - num2 << endl << endl;

            //////////////////////////////////////////////

            // Test 3

            s = "-159753654128647";
            num1.setdecStr(s);
            cout << "num1 = " << num1 << endl;
            s = "365784591235489";
            num2.setdecStr(s);
            cout << "num2 = " << num2 << endl;
            cout << "num1 - num2 = " << num1 - num2 << endl << endl;

            ///////////////////////////////////////////////

            // Test 4

            s = "258745632145112";
            num1.setdecStr(s);
            cout << "num1 = " << num1 << endl;
            s = "-15936548521475";
            num2.setdecStr(s);
            cout << "num2 = " << num2 << endl;
            cout << "num1 - num2 = " << num1 - num2 << endl << endl;

            //////////////////////////////////////////////

            // Test 5

            s = "1258230000000000000001";
            num1.setdecStr(s);
            cout << "num1 = " << num1 << endl;
            s = "3698450000000000000001";
            num2.setdecStr(s);
            cout << "num2 = " << num2 << endl;
            cout << "num1 - num2 = " << num1 - num2 << endl << endl;

        }
        else {
            break;
        }
    }
    return 0;
}
