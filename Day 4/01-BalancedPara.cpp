#include <bits/stdc++.h>
using namespace std;

bool validate(string str)
{
    stack<char> s;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.empty() == true)
            {
                return false;
            }
            char c = s.top();
            s.pop();
            if (c == '(')
            {
                if (c == ')')
                {
                    return true;
                }
            }
            if (c == '{')
            {
                if (c == '}')
                {
                    return true;
                }
            }
            if (c == '[')
            {
                if (c == ']')
                {
                    return true;
                }
            }
        }
    }
    return (s.empty());
}

int main()
{
    string s = "{()}[]";
    string s1 = "{{})]";
    cout << validate(s) << " ";
    cout << validate(s1);
}