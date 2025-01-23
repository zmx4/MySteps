#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		ll n, m;
		cin >> n >> m;
		ll cnt = 1, temp = m;
		while (temp < n)
		{
			temp = pow(m, ++cnt);
		}
		if(abs(temp - n) < abs(pow(m, cnt - 1) - n))
			cout << cnt << endl;
		else
			cout << cnt-1 << endl;
	}

	return 0;
}