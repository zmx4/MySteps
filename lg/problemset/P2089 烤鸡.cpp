#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int n,ans;
vector<vector<int>> res;
void dfs(int u,int sum,vector<int> &a)
{
	if(u == 10)
	{
		if(sum == n)
		{
			ans++;
			res.push_back(a);
		}
		return;
	}
	for(int i = 1; i <= 3; i++)
	{
		a[u] = i;
		dfs(u + 1,sum + i,a);
	}
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n;
	if(n < 10||n > 30)
	{
		cout << 0 << endl;
		return 0;
	}
	vector<int> a(10);
	dfs(0,0,a);
	cout << ans << endl;
	for(auto &i : res)
	{
		for(auto &j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}