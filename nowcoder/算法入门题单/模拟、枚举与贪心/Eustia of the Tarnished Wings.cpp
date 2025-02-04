#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int &i:a)
	{
		cin >> i;
	}
	sort(a.begin(), a.end());
	int cnt = 1;
	for (int i = 0; i < n - 1;i++)
	{
		if(a[i+1]-a[i]>m)
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}