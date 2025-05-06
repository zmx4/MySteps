#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i].first;
	for(int i = 0; i < n; ++i) cin >> a[i].second;
	int sum = 0,ans = 0,maxx = 0;
	for (int i = 0;i < min(n,k);++i)
	{
		sum += a[i].first;
		maxx = max(maxx,a[i].second);
		ans = max(ans,sum+(maxx * (k-i-1)));
	}
	cout << ans << endl;
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