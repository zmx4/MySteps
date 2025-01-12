#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	int am = n;
	n--;
	int j;
	cin >> j;
	while(n--)
	{
		int i;
		cin >> i;
		i = j = __gcd(i, j);
	}
	cout << (ll)j * am;
	return 0;
}