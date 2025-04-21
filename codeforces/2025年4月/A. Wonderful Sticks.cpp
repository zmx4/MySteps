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
	string s;
	cin >> s;
	int cnt = 1;
	vector<int> ans(n + 1, 0);
	s= ' ' + s;
	for (int i = n - 1; i >= 1; i--)
	{
		if (s[i] == '<')
		{
			ans[i + 1] = cnt++;
		}
	}
	for (int i = 1; i <= n ; i++)
	{
		if (!ans[i])
		{
			ans[i] = cnt;
			cnt++;
		}
	}
	for (int i = 1; i <= n; i++)
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