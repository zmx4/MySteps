#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<double> a(n);
	int cnt = 0;
	for (auto &x : a)
	{
		int t;
		cin >> x >> t;
		if (t == 1)
			cnt++;
	}
	int am = min(m, cnt);
	sort(a.begin(), a.end(), greater<int>());
	for (int i = 0; i < am; i++)
	{
		a[i] /= 2;
	}
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	cout << format("{:.1f}", sum) << endl;
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