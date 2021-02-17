#include <bits/stdc++.h>
using namespace std;
string getValue(char c)
{
    switch (c)
    {
    case '2':
        return "abc";
    case '3':
        return "def";
    case '4':
        return "ghi";
    case '5':
        return "jkl";
    case '6':
        return "mno";
    case '7':
        return "pqrs";
    case '8':
        return "tuv";
    case '9':
        return "wxyz";
    default:
        return "";
    }
    return "";
}
vector<string> letterCombinations(string digits)
{
    if (digits.length() == 0)
    {
        return {};
    }

    string value = getValue(digits[0]);
    vector<string> combinations = letterCombinations(digits.substr(1));

    vector<string> res;
    if (combinations.size() > 0)
    {
        for (auto x : value)
        {
            for (auto y : combinations)
            {
                res.push_back(x + y);
            }
        }
    }
    else
    {
        for (auto x : value)
        {
            string output(1, x);
            res.push_back(output);
        }
    }
    return res;
}

int main()
{
    string input = "234";
    vector<string> res = letterCombinations(input);
    for (auto x : res)
    {
        cout << x << endl;
    }
    return 0;
}
