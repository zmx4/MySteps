#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
vector<pair<int, int>> a;
ll ans = inf;
int n;
bool vis[20];
void dfs(int u, ll suan,ll ku)
{
	if(u!=0)ans = min(ans, abs(ku - suan));
	for (int i = 0; i < n;i++)
	{
		if(!vis[i])
		{
			vis[i] = true;
			if(suan!=0)dfs(u + 1, suan * a[i].first, ku + a[i].second);
			else dfs(u + 1, a[i].first, ku + a[i].second);
			vis[i] = false;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin>>n;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	dfs(0, 0, 0);
	cout <<ans<<endl;


	return 0;
}