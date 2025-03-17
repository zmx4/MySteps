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
	vector<int> a(n+1);
	unordered_set<int> s,f;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s.insert(a[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n;i++)
	{
		for (int j = i + 1; j <= n;j++)
		{
			if (s.count(a[i] + a[j]) && f.count(a[i] + a[j]) == 0)
			{
				f.insert(a[i] + a[j]);
				ans++;
			}
		}
		
	}
	cout << ans << endl;
	return 0;
}