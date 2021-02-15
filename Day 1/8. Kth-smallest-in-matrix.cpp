#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<vector<int>> &mat, int k)
{
    int n = mat.size();
    int m = mat[0].size();
    int i = 0;
    int j = 0;
    int res = mat[0][0];

    while (i < n && j < m && k > 0)
    {
        if (mat[i + 1][j] > mat[i][j + 1])
        {
            res = mat[i][j + 1];
            j = j + 1;
        }
        else
        {
            res = mat[i + 1][j];
            i = i + 1;
        }
        k--;
    }
    return res;
}

int main()
{
    vector<vector<int>> mat{{10, 20, 30, 40},
                            {25, 27, 31, 46},
                            {45, 47, 51, 55},
                            {50, 53, 54, 56}};

    int key;
    cin >> key;

    int res = kthSmallest(mat, key);
    cout << "The kth smallest element in the matrix is :" << res << endl;

    return 0;
}
