#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 1e6 + 5;
bitset<MAX> is_prime;

void sieve()
{
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i * i < MAX; ++i)
	{
		if (is_prime[i])
		{
			for (int j = i * i; j < MAX; j += i)
			{
				is_prime[j] = 0;
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	sieve();

	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		if (x == 1)
		{
			cout << "NO\n";
			continue;
		}
		int sq = sqrt(x);
		if (sq * sq == x && is_prime[sq])
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}