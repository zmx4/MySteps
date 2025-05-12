#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	ll n, m;
	cin >> n >> m;
	if (m == 1)
	{
		cout << (n == 1 ? 1 : -1) << endl;
		return;
	}
	if (m < 62)
	{
		ull maxCover = (1ULL << m) - 1;
		if (maxCover < (ull)n)
		{
			cout << -1 << endl;
			return;
		}
	}
	ull X;
	if (m - 1 < 62)
	{
		X = (1ULL << (m - 1)) - 1;
	}
	else
	{
		X = ULLONG_MAX;
	}
	if (X >= (ull)n)
	{
		cout << 1 << endl;
	}
	else
	{
		cout << (n - (ll)X) << endl;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}

	return 0;
}