#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int l, r;
	cin >> l >> r;
	int cnt = 0;
	for (int i = l; i <= r; i++)
	{
		int x = i;
		while (x)
		{
			if (x % 10 == 2)
				cnt++;
			x /= 10;
		}
	}
	cout << cnt << endl;
		return 0;
}