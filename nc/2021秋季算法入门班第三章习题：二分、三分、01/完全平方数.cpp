#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
/*
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	unordered_set<long long> num;
	long long a = 1;
	while (a * a < 1000000000)
	{
		num.insert(a * a);
		a++;
	}
	int n;
	cin >> n;
	while (n--)
	{
		int l, r;
		cin >> l >> r;
		int cnt = 0;
		for (int i = l; i <= r; i++)
		{
			if (num.count(i) > 0)
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}

	return 0;
}
*/
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n;
	cin >> n;
	while (n--)
	{
		/*
		ll l, r;
		cin >> l >> r;
		int cnt = 0;
		cnt = (int)sqrt(r) - (int)sqrt(l);

		if(sqrt(l) * sqrt(l) == l) cnt++;
		*/
		ll l, r;
		cin >> l >> r;
		int sqrtL = (int)sqrt(l);
		int sqrtR = (int)sqrt(r);
		int cnt = sqrtR - sqrtL;
		if ((ll)sqrtL * sqrtL == l)
			cnt++;
		cout << cnt << endl;
	}
}