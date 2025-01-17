#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modExp(ll base, ll exp, ll mod)
{
	if (exp == 0)
		return 1;
	ll result = 1;
	base = base % mod;
	while (exp > 0)
	{
		if (exp % 2 == 1)
		{
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exp = exp / 2;
	}
	return result;
}
int main()
{
	ll a = 16,b=4,e = 65536;
	cout << modExp(a,b,e) << endl;
	return 0;
}