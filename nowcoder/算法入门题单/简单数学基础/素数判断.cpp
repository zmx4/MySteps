#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define int long long
using namespace std;

bool isPrime(int x)
{
	if(x<2)
		return false;
	if (x == 2)
		return 1;
	if (!(x & 1))
		return 0;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	while(n--)
	{
		ll x;
		cin >> x;
		if(isPrime(x))
			cout << "isprime" << endl << x;
		else
			cout << "noprime" << endl;
		// 素因子
		for (ll i = 2; i * i <= x; i++)
		{
			if (x % i == 0)
			{
				if (isPrime(i))
				{
					cout << i << " ";
				}
				if (isPrime(x / i) && x / i != i)
				{
					cout << x / i << " ";
				}
			}
		}
		cout << endl;
	}

	return 0;
}