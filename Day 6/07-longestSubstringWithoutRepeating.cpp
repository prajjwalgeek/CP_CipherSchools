#include <bits/stdc++.h>
using namespace std;
int longestSubsttr(string str)
{
	int n = str.size();
	int res = 0; 
	vector<int> index(256, -1);
	int i = 0;
	for (int j = 0; j < n; j++) {
		i = max(i, index[str[j]] + 1);
		res = max(res, j - i + 1);
		index[str[j]] = j;
	}
	return res;
}

int main()
{
	string str;
	cin>>str;
	int len = longestSubsttr(str);
	cout<<len;	
	return 0;
}
