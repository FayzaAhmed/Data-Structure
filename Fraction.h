#pragma once
#include <iostream>
using namespace std;
class Fraction
{
protected:
	int num, den;
public:

    Fraction();
    Fraction(int top, int bottom);
    Fraction(const Fraction& obj);

    int gcd(int a, int b);
    void reduceFraction();

    bool operator <= (Fraction obj);
    bool operator >= (Fraction obj);
    bool operator == (Fraction obj);
    bool operator != (Fraction obj);

    Fraction operator + (Fraction  obj);
    Fraction operator - (Fraction  obj);
    Fraction operator * (Fraction  obj);
    Fraction operator / (Fraction  obj);

    friend istream& operator >> (istream& in, Fraction& obj);
    friend ostream& operator << (ostream& out, Fraction  obj);

};

