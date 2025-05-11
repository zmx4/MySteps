#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int mn, mx;
	double x, y;
	cin >> x >> y;
	if (y == 1)
		cout << x << " " << x << "\n";
	else
	{
		double e = x - (y - 1) * 0.499999999999999;
		if (e < 0.5)
			mn = 0;
		else
			mn = (int)(e + 0.5);
		double r = x * 1.0 / 0.5;
		if (r < y)
			mx = r;
		else
		{
			double u = y - 1;
			double w = x - 0.5 * (y - 1);
			mx = u + (int)(w + 0.5);
		}
		cout << mn << " " << mx << "\n";
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
		solve();
	}
	
	return 0;
}