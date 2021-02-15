#include <bits/stdc++.h>
using namespace std;

int calcTrappedWater(vector<int> &ar)
{
    int n = ar.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    left[0] = ar[0];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(ar[i], left[i - 1]);
    }
    right[n - 1] = ar[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(ar[i], right[i + 1]);
    }

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        res += (min(left[i], right[i]) - ar[i]);
    }
    return res;
}

int main()
{
    vector<int> ar = {3, 1, 0, 5, 2, 2};
    int res = calcTrappedWater(ar);

    cout << res << endl;

    return 0;
}