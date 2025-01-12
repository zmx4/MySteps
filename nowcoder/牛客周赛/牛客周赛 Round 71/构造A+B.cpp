#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	if (n - 1 > k)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}