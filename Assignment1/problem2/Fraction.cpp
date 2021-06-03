#include "Fraction.h"
using namespace std;

Fraction::Fraction() //Default Consstractor
{
	num = 0;
	den = 1;
}

Fraction::Fraction(int top, int bottom) //Paramitraized Constractor
{
	num = top;
	den = bottom;
	this -> reduceFraction();
}

Fraction::Fraction(const Fraction& obj) //Copy Constractor
{
	num = obj.num;
	den = obj.den;
	this -> reduceFraction();
}

int Fraction::gcd(int a, int b) //Calculate the  Greatest Common Divisor
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

void Fraction::reduceFraction()
{ 
	int d = gcd(num, den);
	num /= d;
	den /= d;
}

bool Fraction::operator<=(Fraction obj) //Overload the boolean operation less than or equal
{
	if ((float)num / den <= (float)obj.num / obj.den)
	{
		return true;
	}
	return false;
}

bool Fraction::operator>=(Fraction obj) //Overload the boolean operation greater than or equal 
{
	if ((float)num / den >= (float)obj.num / obj.den)
	{
		return true;
	}
	return false;
}

bool Fraction::operator==(Fraction obj) //Overload the boolean operation equal
{
	if (num == obj.num && den == obj.den)
	{
		return true;
	}
	return false;
}

bool Fraction::operator!=(Fraction obj) //Overload the boolean operation not equal
{
	if (num == obj.num && den == obj.den)
	{
		return false;
	}
	return true;
}

Fraction Fraction::operator+(Fraction obj) //Overload the arithmetic operation plus
{
	Fraction f;
	f.den = den * obj.den;
	f.num = num * obj.den + obj.num * den;
	f.reduceFraction();
	return f;
}

Fraction Fraction::operator-(Fraction obj) //Overload the arithmetic operation minus
{
	Fraction f;
	f.den = den * obj.den;
	f.num = num * obj.den - obj.num * den;
	f.reduceFraction();
	return f;
}

Fraction Fraction::operator*(Fraction obj) //Overload the arithmetic operation multiplication
{
	Fraction f;
	f.den = den * obj.den;
	f.num = num * obj.num;
	f.reduceFraction();
	return f;
}

Fraction Fraction::operator/(Fraction obj) //Overload the arithmetic operation division
{
	Fraction f;
	f.den = den * obj.num;
	f.num = num * obj.den;
	f.reduceFraction();
	return f;
}

istream& operator>>(istream& in, Fraction& obj) //Overload Extraction operator >>
{
	char divSign;	// used to consume the '/' character during input
	in >> obj.num >> divSign >> obj.den;
	if (obj.den == 0) //The denominator equal zero
	{
		cout << "Can't divide by 0, Enter fraction with denominator greater than 0\n";
		in >> obj.num >> divSign >> obj.den; 
	}
	obj.reduceFraction();
	return in;	
	
}

ostream& operator<<(ostream& out, Fraction obj) //Overload Insertion operator <<
{
	if (obj.den == 0) //The denominator equal zero
	{
		out << "Can't divide by 0" ;
	}
	else if (obj.num == 0) //The numerator equal zero
	{
		out << 0 ;
	}
	else if (obj.den == obj.num) //The denominator equal the numerator
	{
		out << 1 ;
	}
	else
	{
		out << obj.num << '/' << obj.den;
	}
	return out;
}
