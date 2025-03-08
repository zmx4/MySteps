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
	if(n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	vector<int> v(n);
	int maxN = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> v[i];
		maxN = max(maxN, v[i]);
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans += maxN - v[i];
	}
	cout << ans << endl;

	return 0;
}