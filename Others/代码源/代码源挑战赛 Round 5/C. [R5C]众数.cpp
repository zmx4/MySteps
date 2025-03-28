#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	map<int, int> mp;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		mp[x]++;
		a[i] = x;
	}
	vector<int> cnt(n+1,0);
	for(int i = 0; i < n; ++i)
	{
		cnt[mp[a[i]]]++;
	}
	int ans = 0,count = 0;
	for(int i = n; i >= 0; --i)
	{
		if(cnt[i]>count)
		{
			count = cnt[i];
			ans = i;
		}
	}
	cout << ans << endl;



	return 0;
}