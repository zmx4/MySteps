#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

vector<bool> sieve(int n)
{
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	return is_prime;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;
	cin >> s;
	int len = s.length();
	int one = 0;
	vector<int> pre(len + 1, 0);
	for (int i = 0; i < len; i++)
	{
		pre[i + 1] = pre[i] + (s[i] == '1');
	}
	one = pre[len];
	vector<bool> is_prime = sieve(one);
	vector<int> fre(len + 1, 0);
	for (int i = 0; i <= len; i++)
	{
		fre[pre[i]]++;
	}
	ll ans = 0;
	for (int k = 2; k <= one;k++)
	{
		if(!is_prime[k])
			continue;
		for (int i = 0; i + k <= one;i++)
		{
			ans += (ll)fre[i] * fre[i + 1];
		}
	}
	cout << ans << endl;
	return 0;
}