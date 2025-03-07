#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	while(k--)
	{
		int x;
		cin >> x;
		auto it = lower_bound(a.begin(), a.end(), x);
		if(it == a.end() || *it != x)
			cout << -1 << " ";
		else
			cout << it - a.begin() + 1 << " ";
	}

	return 0;
}