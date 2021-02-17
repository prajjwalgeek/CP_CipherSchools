#include <bits/stdc++.h>
using namespace std;

void solve(string s, int l, int r, vector<string> &res)
{
    if (l > r)
    {
        return;
    }
    if (l == 0 && r == 0)
    {
        res.push_back(s);
        return;
    }
    if (l > 0)
    {
        solve(s + "(", l - 1, r, res);
    }
    if (r > 0)
    {
        solve(s + ")", l, r - 1, res);
    }
}

vector<string> AllParenthesis(int n)
{
    vector<string> res;
    solve("", n, n, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> res = AllParenthesis(n);

    for (auto x : res)
        cout << x << endl;

    return 0;
}
