#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<string> s(n, string(n, ' '));
	for (int i = 0; i < n; ++i)
	{
		s[0][i]='#';
		s[n-1][i]='#';
	}
	for(int i = 0; i < n; ++i)
	{
		s[i][0]='#';
		s[i][n-1]='#';
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << s[i][j];
		}
		cout << endl;
	}
	return 0;
}