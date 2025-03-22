#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, m, q;
	cin >> n >> m >> q;
	unordered_set<int> col, row;
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		if(x==0)row.insert(y);
		else col.insert(y);
	}
	cout << n * m - row.size() * m - col.size() * n + row.size() * col.size() << endl;
	return 0;
}