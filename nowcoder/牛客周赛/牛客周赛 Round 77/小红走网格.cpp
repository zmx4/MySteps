#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int gcd(int a,int b)
{
	while(b!=0)
	{
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin >> T;
	while(T--)
	{
		int x, y, a, b, c, d;
		cin >> x >> y >> a >> b >> c >> d;
		ll ax = gcd(c, d);
		ll ay = gcd(a, b);
		if (abs(x) % ax == 0 && abs(y) % ay == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;

}