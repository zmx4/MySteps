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
	vector<int> a(n + 1);
	for (int i = 1; i <= n;i++)cin >> a[i];
	vector<int> left(n + 1), right(n + 1);
	for (int i = 1; i <= n;i++)left[i] = left[i-1] + (a[i] <= k);
	for (int i = n; i >= 1;i--)right[i] = right[i+1] + (a[i] > k);
	bool flag = false;
	int cnt = 0;
	for (int i = 1; i <= n;i++)
	{
		cnt += left
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