#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll Gcd(ll a, ll b)
{
	return b ? Gcd(b, a % b) : a;
}

bool isPrime(ll n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	for (ll i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	ll n;
	cin >> n;

	if(n==2)
	{
		cout<<"No"<<endl;
	}
	else if(n==1)
	{
		cout<<"Yes"<<endl;
	}
	else 
	{
		ll xiao = 0;
		ll num = n-1;
		while(!isPrime(num))
		{
			num--;
		}
		cout << num << endl;
		if(isPrime(n-num))
		{
			cout << "Yes" << endl;
		}
		else 
		{
			cout << "No" << endl;
		}
	}

	return 0;
}