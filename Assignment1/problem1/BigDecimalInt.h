#pragma once
#include<iostream>
using namespace std;
class BigDecimalInt
{

private:

    string desStr;

public:

    BigDecimalInt();
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);

    void setdecStr(string s);
    string getdecStr();
    int getsize();

    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    BigDecimalInt operator= (BigDecimalInt anotherDec);
    friend ostream& operator << (ostream& out, BigDecimalInt b);

};

