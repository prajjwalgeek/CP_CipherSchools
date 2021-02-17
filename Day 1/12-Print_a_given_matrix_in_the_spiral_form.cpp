#include <bits/stdc++.h>
using namespace std;
void spiralPrint(vector<vector<int>>& ar, int i, int j, int m, int n)
{
	if (i >= m or j >= n)
		return;

	for (int p = j; p < n; p++)
		cout << ar[i][p] << " ";

	for (int p = i + 1; p < m; p++)
		cout << ar[p][n - 1] << " ";

	if ((m - 1) != i)
		for (int p = n - 2; p >= j; p--)
			cout << ar[m - 1][p] << " ";

	if ((n - 1) != j)
		for (int p = m - 2; p > i; p--)
			cout << ar[p][j] << " ";

	spiralPrint(ar, i + 1, j + 1, m - 1, n - 1);
}

int main()
{
	vector<vector<int>> ar{{ 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 }};
    int m = ar.size();
    int n = ar[0].size();
	spiralPrint(ar, 0, 0, m,n);
	return 0;
}
