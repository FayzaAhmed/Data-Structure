// P5_ ListPermutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
vector<string> v;
bool Not_exist(string s) { // Check if this word is not exist in my vector
    int x = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == s)
        {
            x = 1; break;
        }
    }
    if (x == 1) // Already exist
        return false;
    else // Not exist store this word in my vector and return true
    {
        v.push_back(s);
        return true;
    }
}
void RecPermute(string soFar, string rest)
{
    if (rest == "") // No more characters
    {
        if (Not_exist(soFar))
            cout << soFar << endl; // Print the word if it not duplicate
    }

    else // Still more chars
        // For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i) + rest.substr(i + 1); RecPermute(next, remaining);
        }
}
// "wrapper" function
void ListPermutations(string s) {
    RecPermute("", s);
}
int main()
{
    string s = "Makka";
    ListPermutations(s);
    return 0;
}
