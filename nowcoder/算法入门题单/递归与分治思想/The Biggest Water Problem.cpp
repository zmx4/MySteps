#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	ll n;
	cin >> n;
	ll temp = n;
	while (n >= 10)
	{
		ll temp = n;
		ll sum = 0;
		while(temp>10)
		{
			ll x = temp % 10;
			temp /= 10;
			sum += x;
		}
		n = sum+temp;
	}
	cout<<n<<endl;
	return 0;
}