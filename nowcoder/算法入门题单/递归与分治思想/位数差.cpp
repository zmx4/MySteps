#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 1e5 + 10;
int a[N];
ll b[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int weishucha(ll a, ll b)
{
	if (b == 0)
		b == 1;
	b += a;
	int res = to_string(b).size() - to_string(a).size();
	return res;
}

ll calc(ll l, ll r)
{
	if (r == l)
		return 0;
	ll mid = (l + r) >> 1;
	ll res = calc(l, mid) + calc(mid + 1, r);
	sort(a + mid + 1, a + r + 1);
	for (int i = l; i <= mid; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (b[j] - a[i] > 0)
			{
				auto en = a + r + 1;
				auto it = lower_bound(a + mid + 1, a + r + 1, b[j] - a[i]);
				res += en - it;
			}
		}
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << calc(1, n + 1) << endl;
	return 0;
}