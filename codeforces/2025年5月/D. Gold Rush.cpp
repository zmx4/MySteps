#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
bool flag;
int n, m;
void dfs(int x)
{
	if (flag)
		return;
	if (x == m)
	{
		flag = true;
		return;
	}
	if (x < m)
		return;
	if (x % 3 != 0)
		return;
	dfs(x / 3);
	dfs(x / 3 * 2);
}
void solve()
{
	cin >> n >> m;
	if(m>n)
	{
		cout << "NO" << endl;
		return;
	}
	flag = false;
	dfs(n);
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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
		solve();
	}
	
	return 0;
}