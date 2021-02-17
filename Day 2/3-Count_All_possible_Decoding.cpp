#include <bits/stdc++.h>
using namespace std;

void Decodings(string s, string res, vector<string> &ans)
{
    if (s.length() == 0)
    {
        ans.push_back(res);
        return;
    }

    int firstChar = stoi(s.substr(0, 1));
    char letter = 'a' + firstChar - 1;

    Decodings(s.substr(1), res + letter, ans);

    if (s.length() >= 2)
    {
        int firstTwoChar = stoi(s.substr(0, 2));
        if (firstTwoChar <= 26)
        {
            char letterTwo = 'a' + firstTwoChar - 1;
            Decodings(s.substr(2), res + letterTwo, ans);
        }
    }
}

int main()
{
    string s;
    cin >> s;
    vector<string> res;
    Decodings(s, "", res);
    for (auto x : res)
    {
        cout << x << " " << endl;
    }
    return 0;
}
