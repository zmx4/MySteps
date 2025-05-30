#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n, x;
	cin >> n >> x;
	vector<int> ans(n);
	if(x>=n)
	{
		for (int i = 0; i < n;i++)
			ans[i] = i;
	}
	if(x<n)
	{
		for (int i = 0; i < n; i++)
			ans[i] = i;
		swap(ans[x], ans[n - 1]);
	}
	for (int i = 0; i < n;i++)
		cout << ans[i] << " ";
	cout << endl;
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