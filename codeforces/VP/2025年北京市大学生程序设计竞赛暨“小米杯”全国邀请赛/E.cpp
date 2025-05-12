#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n;
	cin >> n;
	vector<pair<double, double>> p(n);
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	double a, b, c;
	cin >> a >> b >> c;
	double x0, y0;
	if (fabs(b) > 1e-12)
	{
		x0 = 0;
		y0 = -c / b;
	}
	else
	{
		y0 = 0;
		x0 = -c / a;
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