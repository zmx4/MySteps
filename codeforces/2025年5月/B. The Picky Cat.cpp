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
	ll a1;
	cin >> a1;
	vector<ll> a(n);
	a[0] = a1;
	for (int i = 1; i < n; i++)
	{
		cin >> a[i];
	}
	int m = (n + 1) / 2;
	ll abs1 = llabs(a1);
	int cnt1 = 0;
	for (int i = 1; i < n; i++)
	{
		if (llabs(a[i]) < abs1)
			cnt1++;
	}
	int cnt2 = (n - 1) - cnt1;
	auto check = [&]() -> bool
	{
		if (cnt1 <= m - 1 && m - 1 <= cnt1 + cnt2)
			return true;
		if (cnt2 >= m - 1)
			return true;
		return false;
	};
	if(check())
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