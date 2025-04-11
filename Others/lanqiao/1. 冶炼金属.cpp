#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> maxn(n + 1, 0), minn(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		int past = x / y;
		int now = x / y;
		while(x/now == y)
		{
			past = now;
			now--;
		}
		maxn[i] = past;
		past = x / y;
		now = x / y;
		while (x / now == y)
		{
			past = now;
			now++;
		}
		minn[i] = past;
	}
	int ans1 = -1, ans2 = inf;
	for (int i = 1; i <= n; i++)
	{
		if (maxn[i] > ans1) ans1 = maxn[i];
		if (minn[i] < ans2) ans2 = minn[i];
	}
	cout<<ans1 << " " << ans2 << endl;
	return 0;
}