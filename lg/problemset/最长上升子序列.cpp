#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 10;
int f[N], d[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}
	for(int i = 0; i < n; i++)
	{
		f[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (d[j] < d[i])
			{
				f[i] = max(f[i], f[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}