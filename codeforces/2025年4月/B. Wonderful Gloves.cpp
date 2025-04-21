#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
#define int long long
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1, 0), b(n + 1, 0);
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++)cin >> b[i];
	vector<int> l(n + 1, 0), r(n + 1, 0);
	int ans = 0;
	for (int i = 1;i <= n; i++)
	{
		ans+=max(a[i], b[i]);
		l[i] = min(a[i], b[i]);
	}
	sort(l.begin() + 1, l.end(), greater<int>());
	for (int i = 1; i < k; i++)
	{
		ans += l[i];
	}
	cout << ans+1 << endl;
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