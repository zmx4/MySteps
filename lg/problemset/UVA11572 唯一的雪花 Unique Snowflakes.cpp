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
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	unordered_map<int, int> last;
	last.reserve(n * 2);
	int l = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x = a[i];
		if (last.count(x) && last[x] >= l)
			l = last[x] + 1;
		last[x] = i;
		ans = max(ans, i - l + 1);
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