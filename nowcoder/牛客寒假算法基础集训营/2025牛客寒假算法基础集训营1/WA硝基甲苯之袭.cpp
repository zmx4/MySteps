#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 2e5 + 5;
ll ans = 0;
vector<int> a(2 * N + 1);
void solve(const int x, int y)
{
	y += x;
	if ((x ^ y) == gcd(x, y))
	{
		ans += (ll)a[x] * a[y];
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		a[x] = i;
	}

	for (int i = 2; i <= N; i += 2)
	{
		for (int j = 1; j * j <= i; j++)
		{
			if (i % j)
				continue;
			solve(i, j);
			if (i != j * j)
			{
				int t = i / j;
				solve(i, t);
			}
		}
	}
	cout << ans << endl;
}