#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool prime(long long n)
{
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (!(n & 1))
		return 0;
	for (long long i = 3; i * i <= n; i += 2)
		if (!(n % i))
			return 0;
	return 1;
}
int main()
{
	ll t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (prime(n))
		{
			cout << "isprime" << endl
				 << n;
		}
		else
			cout << "noprime" << endl;
		for (ll i = 2; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				if (prime(i))
				{
					cout << i << " ";
				}
				if (prime(n / i) && n / i != i)
				{
					cout << n / i << " ";
				}
			}
		}
		cout << endl;
	}
	return 0;
}