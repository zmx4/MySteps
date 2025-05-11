#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 5e5+10;
#define int long long
int a[N], q[N], head = 0, tail = -1;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n),b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	b = a;
	sort(b.begin(), b.end());
	vector<int> c(n - 1);
	for (int j = 0; j + 1 < n; j++)
	{
		c[j] = b[j + 1] - b[j];
	}
	ll ans = LLONG_MAX;
	for (int i = 0; i < n - 1; i++)
	{
		while (head <= tail && c[q[tail]] >= c[i])
			tail--;
		q[++tail] = i;
		if (head <= tail && i - (k - 2) > q[head])
			head++;
		if (i >= k - 2)
		{
			int j = i - (k - 2);
			ll minn = c[q[head]];
			ll maxx = b[j + k - 1] - b[j];
			ans = min(ans, maxx * minn);
		}
	}
	cout << ans << endl;
	return 0;
}