#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	long long int n, a, b, c;
	cin >> n >> a >> b >> c;

	long ans = 0;

	while(n > a)
	{
		n -= a;
		ans++;
	}
	while(n > b)
	{
		n -= b;
		ans++;
	}
	while(n > c)
	{
		n -= c;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}