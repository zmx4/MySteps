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
	tuple<int, int, int> a[n];
	for(int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		a[i] = {x, y, z};
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++)
	{
		cout << get<0>(a[i]) << " " << get<1>(a[i]) << " " << get<2>(a[i]) << endl;
	}

	return 0;
}