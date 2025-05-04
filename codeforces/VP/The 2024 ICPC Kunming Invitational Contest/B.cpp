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
	vector<int> a(n);
	for (int i = 0; i < n;i++)
		cin >> a[i];
	int m;
	cin >> m;
	vector<int> tar(n);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cnt += a[i] / k;
		int x = a[i] % k;
		tar[i] = k - x;
	}
	int ans = 0;
	ranges::sort(tar);
	for (int i = 0; i < n;i++)
	{
		if (m - tar[i] < 0)
			break;
		else
		{
			m -= tar[i];
			ans++;
		}
	}
	ans += (m / k);
	cout << ans + cnt << endl;
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