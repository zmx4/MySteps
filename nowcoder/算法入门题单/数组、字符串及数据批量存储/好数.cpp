#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool isGoodNum(int x)
{
	int b = x / 100,s =x / 10 % 10,g = x % 10;
	int num = b * s;
	if(num%10==g)
		return true;
	return false;
}

void solve()
{
	int l, r;
	cin >> l >> r;
	int ans = 0;
	for (int i = l; i <= r; i++)
	{
		if (isGoodNum(i))
		{
			ans++;
			//cout << i << endl;
		}
	}
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}