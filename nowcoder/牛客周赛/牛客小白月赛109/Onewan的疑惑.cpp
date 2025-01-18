#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n;
	cin >> n;

	long long maxn = 19260817 + 114514;

	if (n >= maxn)
	{
		cout << maxn + 1 << endl;
	}
	else
	{
		cout << n << endl;
	}

	return 0;
}