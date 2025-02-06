#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int MOD = 10007;

long long modExp(long long base, long long exp, const long long &mod)
{
	long long result = 1;
	base = base % mod; // 处理 base 大于 mod 的情况
	while (exp > 0)
	{
		// 如果 exp 是奇数，将 base 乘到结果上
		if (exp % 2 == 1)
		{
			result = (result * base) % mod;
		}
		// exp 是偶数，将 base 平方并减少 exp 一半
		base = (base * base) % mod;
		exp = exp / 2;
	}
	return result;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	ll n, c;
	cin >> n >> c;
	if(n==1)
	{
		cout << c << endl;
		return 0;
	}

	else if(n == 2)
	{
		cout << (c * (c - 1)) % MOD << endl;
		return 0;
	}

	else
	{
		ll ba = modExp(c - 1,n,MOD);
		ll res;
		if(n%2==0)
		{
			res = (ba + (c - 1)) % MOD;
		}
		else
		{
			res = (ba - (c - 1)) % MOD;
			if(res < 0)
			{
				res += MOD;
			}
		}
		cout << res << endl;
	}

	return 0;
}