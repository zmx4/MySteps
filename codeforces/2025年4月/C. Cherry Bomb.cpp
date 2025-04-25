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
	int tar = -1;
	bool flag = true;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		if (a[i] != -1 && b[i] != -1)
		{
			int tmp = a[i] + b[i];
			if (tar == -1)
				tar = tmp;
			else if (tmp != tar)
				flag = false;
		}
	}
	if (tar != -1)
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] > tar || b[i] > tar)
				flag = false;
			if(tar - a[i] > k)
				flag = false;
		}
	}
	if (!flag)
	{
		cout << 0 << endl;
		return;
	}
	else if (tar != -1)
	{
		cout << 1 << endl;
		return;
	}
	int x = *max_element(a.begin(), a.end()), y = *min_element(a.begin(), a.end());
	long long diff = 1LL * x - y;
	long long ans = 1LL * k - diff + 1;
	if (ans < 0)
		ans = 0;
	cout << ans << endl;
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