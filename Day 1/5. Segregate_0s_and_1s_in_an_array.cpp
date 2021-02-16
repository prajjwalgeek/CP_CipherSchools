#include <bits/stdc++.h>
using namespace std;

void sort01(vector<int> &ar)
{
    int i = 0;
    int j = ar.size() - 1;

    while (i < j)
    {
        if (ar[i] == 1 && ar[j] == 0)
        {
            swap(ar[i], ar[j]);
            i++;
            j--;
        }
        else
        {
            if (ar[i] == 0)
            {
                i++;
            }
            if (ar[j] == 1)
            {
                j--;
            }
        }
    }
}

int main()
{
    vector<int> ar = {0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0};
    sort01(ar);

    for (auto x : ar)
        cout << x << " ";
    cout << endl;
    return 0;
}