#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1), b(m);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	ranges::sort(b);
	a[1] = min(a[1], b[0] - a[1]);
	for (int i = 2; i <= n;i++)
	{
		if(a[i-1]<=max(a[i], b[0]-a[i]))
		{
			if (min(a[i], b[0] - a[i])>= a[i-1])
				a[i] = min(a[i], b[0] - a[i]);
			else
				a[i] = max(a[i], b[0] - a[i]);
		}
		else
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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