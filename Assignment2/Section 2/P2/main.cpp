// Stack_Brackets.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Stack.h"

using namespace std;

//Function to test if its parameters are opening and closing parenthesis.
bool isPair(char openning, char closing)
{
    if (openning == '(' && closing == ')')
        return true;

    if (openning == '[' && closing == ']')
        return true;

    if (openning == '{' && closing == '}')
        return true;
    return false;
}

//Function to check the string validation.
bool isValid(string text)
{
    Stack<char> check;
    bool openComment = false;
    for (int i = 0; i < text.size(); i++)
    {
        if (!openComment && text[i] != '*')
        {
            if (text[i] == '(' || text[i] == '{' || text[i] == '[')
            {
                check.push(text[i]);
            }
            else if ((text[i] == '/') && (text[i + 1] == '*'))
            {
                 check.push(text[i]);
                 check.push(text[i + 1]);
                 i += 2;
                 openComment = true;
            }
            else if (text[i] == ')' || text[i] == '}' || text[i] == ']')
            {
                 //checking if the stack is empty or the parenthesis not pairs.
                if ((check.isEmpty()) || !isPair(check.top(), text[i]))
                {
                    return false;
                }
                 else
                     check.pop();
            }
        }
        //handling comment closing.
        else if ((i + 1 != text.size()) && (text[i] == '*') && (text[i + 1] == '/'))
        {
            if (!check.isEmpty() && check.top() == text[i])
            {
                check.pop();//deleting from stack.
                check.pop();
                i++;
                openComment = false; //Now we found the comment closing.
            }
            else
                return false;
        }

    } // for ended
    if (!check.isEmpty()) return false;
    return true;
}



int main()
{

    string test = "([{}])(){}[]{[]} ";
    if (isValid(test))
        cout << "Valid" << endl;
    else
        cout << "InValid" << endl;
    string test1 = "({)}";
    if (isValid(test1))
        cout << "Valid" << endl;
    else
        cout << "InValid" << endl;


    string test2 = " ({/*)}]]]]]]}*/}) ";
    if (isValid(test2))
        cout << "Valid" << endl;
    else
        cout << "InValid" << endl;


    string test3 = "({/*[][[]]]]]}) ";
    if (isValid(test3))
        cout << "Valid" << endl;
    else
        cout << "InValid" << endl;


    string test4 = "  [{/*******/}]   ";
    if (isValid(test4))
        cout << "Valid" << endl;
    else
        cout << "InValid" << endl;


}
