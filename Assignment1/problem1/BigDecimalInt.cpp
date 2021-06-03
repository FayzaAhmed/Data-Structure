#include "BigDecimalInt.h"
#include "BigDecimalInt.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
BigDecimalInt::BigDecimalInt() //Default Consstractor
{
    desStr = "";
}
BigDecimalInt::BigDecimalInt(string decStr) // Paramitraized Constractor
{
    this->desStr = decStr;
}
BigDecimalInt::BigDecimalInt(int decInt) // Paramitraized Constractor
{
    this->desStr = to_string(decInt);
}
void BigDecimalInt::setdecStr(string s) // to set the number in string
{
    desStr = s;
}
string BigDecimalInt::getdecStr() // to get the number
{
    return desStr;
}
int BigDecimalInt::getsize() // to get the size of number
{
    return desStr.size();
}
BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt anotherDec) // Overload the arithmetic operation ( + )
{
    BigDecimalInt num3;
    string r = "";
    int s1 = this->getsize(), l = 0, rr = 0;
    int s2 = anotherDec.getsize();
    if (this->desStr[0] == '-' && anotherDec.desStr[0] != '-')
    {
        anotherDec.desStr = string(1, '-') + anotherDec.desStr;
        return *this - anotherDec;
    }
    if (this->desStr[0] != '-' && anotherDec.desStr[0] == '-')
    {
        anotherDec.desStr.erase(anotherDec.desStr.begin(), anotherDec.desStr.begin() + 1);
        return *this - anotherDec;
    }
    if (this->desStr[0] == '-') l = 1;
    if (anotherDec.desStr[0] == '-') rr = 1;
    int i = 0, j = 0, c = 0;
    while (i < s1 - l || j < s2 - rr || c > 0) {
        int t = c;
        if (i < s1 - l)
            t += this->desStr[s1 - i - 1] - '0';
        else
            t += 0;
        if (j < s2 - rr)
            t += anotherDec.desStr[s2 - j - 1] - '0';
        else
            t += 0;
        r = string(1, t % 10 + '0') + r;
        c = t / 10;
        i++;
        j++;
    }
    if (l == 1 && rr == 1) r = string(1, '-') + r;
    num3.setdecStr(r);
    return  num3;
}
BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec) // Overload the arithmetic operation ( - )
{
    BigDecimalInt num3;
    string r = "", ss = this->desStr, rr = anotherDec.desStr;
    int s1 = this->getsize(), t;
    int s2 = anotherDec.getsize();
    int c = 0, sub, f = 0;
    if (ss[0] == '-' && rr[0] != '-')
    {
        anotherDec.desStr = string(1, '-') + anotherDec.desStr;
        return *this + anotherDec;
    }
    if (rr[0] == '-' && ss[0] != '-')
    {
        anotherDec.desStr.erase(anotherDec.desStr.begin(), anotherDec.desStr.begin() + 1);
        return *this + anotherDec;
    }
    if (rr[0] == '-' && ss[0] == '-')
    {
        rr.erase(rr.begin(), rr.begin() + 1);
        ss.erase(ss.begin(), ss.begin() + 1);
        s2--; s1--;
        if (s2 > s1)
        {
            swap(ss, rr);
        }
        else if (s1 > s2)
        {
            f = 1;
        }
        else
        {
            for (int i = 0; i < s2; i++)
            {
                if (ss[i] < rr[i])
                {
                    swap(ss, rr);
                    break;
                }
                else if (ss[i] > rr[i])
                    f = 1;
                break;
            }
        }
        goto down;
    }
    if (s2 > s1)
    {
        swap(ss, rr);
        f = 1;
    }
    else if (s1 > s2)
    {
    }
    else
    {
        for (int i = 0; i < s2; i++)
        {
            if (ss[i] < rr[i])
            {
                swap(ss, rr);
                f = 1;
                break;
            }
            else if (ss[i] > rr[i])
                break;
        }
    }
down:
    reverse(ss.begin(), ss.end());
    reverse(rr.begin(), rr.end());
    for (int i = 0; i < s2; i++)
    {
        sub = ((ss[i] - '0') - (rr[i] - '0')) - c;
        if (sub < 0)
        {
            sub += 10;
            c = 1;
        }
        else
        {
            c = 0;
        }
        r.push_back(sub + '0');
    }
    for (int i = s2; i < s1; i++)
    {
        sub = (ss[i] - '0') - c;
        c = 0;
        r.push_back(sub + '0');
    }
    reverse(r.begin(), r.end());
    if (f)
        r = string(1, '-') + r;
    num3.setdecStr(r);
    return num3;
}
BigDecimalInt BigDecimalInt::operator= (BigDecimalInt anotherDec) // Overload the arithmetic operation ( = )
{
    BigDecimalInt num3(anotherDec.desStr);
    return num3;
}
ostream& operator << (ostream& out, BigDecimalInt b) // Overload Insertion operator ( << )
{
    out << b.desStr;
    return out;
}
