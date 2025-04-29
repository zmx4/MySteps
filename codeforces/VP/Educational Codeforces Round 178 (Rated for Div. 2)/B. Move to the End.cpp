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
	vector<ll> a(n + 1);
	multiset<ll,greater<int>> s;
	for (int i = 1; i <= n;i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	vector<ll> pmax(n + 1, 0);
	pmax[1] = a[1];
	for (int i = 2; i <= n; i++)
	{
		pmax[i] = max(pmax[i - 1], a[i]);
	}
	vector<ll> sfx(n + 1, 0);
	for (int k = 1; k <= n; k++)
	{
		sfx[k] = sfx[k - 1] + a[n - k + 1];
	}
	for (int i = 1; i <= n;i++)
	{
		ll sum1 = sfx[i];
		ll sum2 = (n - i + 1 >= 1 ? sfx[i - 1] + pmax[n - i + 1] : LLONG_MIN);
		cout << max(sum1, sum2) << (i == n ? endl : " ");
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