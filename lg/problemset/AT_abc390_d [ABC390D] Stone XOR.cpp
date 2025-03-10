#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

int n, a[14], b[14];
unordered_set<int> s;
void dfs(int x,int m)
{
	if(x==n)
	{
		int sum = 0;
		for(int i = 0; i <= m; i++)
			sum ^= b[i];
		s.insert(sum);
		return;
	}
	for (int i = 0; i <= m;i++)
	{
		b[i]+=a[x];
		if(i<m)
			dfs(x + 1, m);
		else
			dfs(x + 1, m + 1);
		b[i] -= a[x];
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);


	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	dfs(0, 0);
	cout << s.size() << endl;
	return 0;
}