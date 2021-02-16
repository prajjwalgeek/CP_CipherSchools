#include <bits/stdc++.h>
using namespace std;

vector<int> alternateSort(vector<int> &ar)
{
    sort(ar.begin(), ar.end());
    vector<int> res;
    int i = 0;
    int j = ar.size() - 1;

    while (i <= j)
    {
        if (i == j)
        {
            res.push_back(ar[j]);
        }
        else
        {
            res.push_back(ar[j]);
            res.push_back(ar[i]);
        }
        i++;
        j--;
    }
    return res;
}

int main()
{
    vector<int> ar = {7, 1, 2, 3, 4, 5, 6};
    vector<int> res = alternateSort(ar);

    for (auto x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}