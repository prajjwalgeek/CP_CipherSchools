#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, int m)
{
    if (n == 1 || m == 1)
        return 1;
    return countPaths(n - 1, m) + countPaths(n, m - 1);
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << countPaths(n, m) << endl;
    return 0;
}
