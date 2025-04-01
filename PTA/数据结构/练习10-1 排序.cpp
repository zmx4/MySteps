#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;cin>> n;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	stable_sort(a.begin() + 1, a.end());
	for (int i = 1; i <= n; i++)
	{
		cout << a[i];
		if (i != n) cout << " ";
	}

	return 0;
}