#include <bits/stdc++.h>
using namespace std;

int findCandidate(vector<int> &ar)
{
    int majorityCount = 1, majorityIndex = 0;
    int n = ar.size();

    for (int i = 1; i < n; i++)
    {
        if (ar[i] == ar[majorityIndex])
        {
            majorityCount++;
        }
        else
        {
            majorityCount--;
        }

        if (majorityCount == 0)
        {
            majorityIndex = i;
        }
    }
    return ar[majorityIndex];
}

void findMajority(vector<int> &ar)
{
    int candidate = findCandidate(ar);
    int cnt = 0;
    int n = ar.size();

    for (int i = 0; i < n; i++)
    {
        if (ar[i] == candidate)
        {
            cnt++;
        }
    }
    if (cnt > (n / 2))
    {
        cout << candidate << endl;
    }
    else
    {
        cout << "Their is no majority element." << endl;
    }
}

int main()
{
    vector<int> ar = {1, 3, 3, 3, 2};
    findMajority(ar);
    return 0;
}