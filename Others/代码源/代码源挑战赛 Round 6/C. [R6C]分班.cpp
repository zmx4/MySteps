#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;cin>>n;
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++)cin>>a[i];
	int m;cin>>m;
	unordered_map<int,unordered_set<int>> mp;
	int u, v;
	for(int i = 0; i < m; i++)
	{
		cin>>u>>v;
		mp[u].insert(v);
		mp[v].insert(u);
	}
	vector<int> res(n + 1, 0);
	ll sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; i++)
	{
		bool flag1 = false, flag2 = false;
		for (auto j : mp[i])
		{
			if (j < i && res[j] != 0)
			{
				if (res[j] == 1)
					flag1 = true;
				else if (res[j] == 2)
					flag2 = true;
			}
		}
		if (flag1 && flag2)
		{
			res[i] = -1;
		}
		else if (flag1)
		{
			res[i] = 2;
			sum2 += a[i];
		}
		else if (flag2)
		{
			res[i] = 1;
			sum1 += a[i];
		}
		else
		{
			if (sum1 <= sum2)
			{
				res[i] = 1;
				sum1 += a[i];
			}
			else
			{
				res[i] = 2;
				sum2 += a[i];
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << endl;
	return 0;
}