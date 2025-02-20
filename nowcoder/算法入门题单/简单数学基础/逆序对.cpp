#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int mod = 1e9 + 7;

long long modPow(long long a, long long b, int mod)
{
	long long res = 1;
	while (b)
	{
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;

	if (n < 2)
	{
		cout << 0 << "\n";
		return 0;
	}
	// 计算 2^(n-2) mod mod
	long long two = modPow(2, n - 2, mod);
	long long pairCount = (1LL * n * (n - 1) / 2) % mod;
	long long ans = (pairCount % mod) * two % mod;
	cout << ans % mod << "\n";

	return 0;
}