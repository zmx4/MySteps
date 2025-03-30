#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x, y;
	cin >> x >> y;
	cout << 100 * 100 / 2 - (y * 100 / 2) - ((100 - x) * 100 / 2);

	return 0;
}