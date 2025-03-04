#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int m;
	while (cin >> m)
	{
		if (m == -1)
			break;
		for (int i = 0; i < n; ++i)
		{
			if (a[i] == m)
			{
				cout << i + 1 << " ";
				break;
			}
			if (i == n - 1)
				cout << 0 << " ";
		}
	}

	return 0;
}