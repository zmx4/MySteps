#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n;
	string s;
	cin >> n >> s;
	vector<int> cnt(2, 0);
	for (int i = 0; i < n;i++)
		cnt[s[i] - '0']++;
	int ans = 0;
	ans += cnt[0] * (cnt[1] + 1);
	ans += cnt[1] * (cnt[1] - 1);
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