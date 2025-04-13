#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	while(q--)
	{
		int x;
		cin >> x;
		auto it1 = lower_bound(a.begin(), a.end(), x);
		auto it2 = upper_bound(a.begin(), a.end(), x) - 1;
		if(it1 == a.end() || *it1 != x)
			cout << "-1 -1" << endl;
		else
		{
			int l = it1 - a.begin(), r = it2 - a.begin();
			cout << l<<" " << r << endl;
		}
	}

	return 0;
}