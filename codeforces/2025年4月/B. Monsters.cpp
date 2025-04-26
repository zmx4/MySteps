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
	// priority_queue<pair<int, int>, vector<pair<int, int>>, [](pair<int, int> { return ; })> pq;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] %= k;
		if (!a[i])
			a[i] = k;
	}
	vector<pair<int, int>> b(n + 1);
	for (int i = 1; i <= n; i++)
	{
		b[i].first = a[i];
		b[i].second = i;
	}
	stable_sort(b.begin() + 1, b.end(), [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });
	for(int i = 1; i <= n; i++)
	{
		cout << b[i].second << " ";
	}
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}

	return 0;
}