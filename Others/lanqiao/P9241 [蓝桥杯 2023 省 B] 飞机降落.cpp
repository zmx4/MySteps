#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
bool flag = false;
bool vis[15] = {false};
int n;
struct plane
{
	int t, d, l;
};
plane p[15];
void dfs(int u, int tt)
{
	if (u == n)
	{
		flag = true;
		return;
	}
	if (flag)
		return;
	for (int i = 0; i < n; i++)
	{
		if (vis[i] || p[i].d < tt)
			continue;
		vis[i] = true;
		dfs(u + 1, max(tt + p[i].l, p[i].t + p[i].l));
		vis[i] = false;
	}
}
void solve()
{
	cin>> n;
	//vector<plane> p(n);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i].t >> p[i].d >> p[i].l;
		p[i].d += p[i].t;
	}
	dfs(0,0);
	if(flag)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	while(T--)
	{
		flag = false;
		solve();
	}
	
	return 0;
}