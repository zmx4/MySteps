#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;


struct node{
	int a, b;
};

void solve()
{
	node a[500005];
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].a >> a[i].b;
	}
	vector<int>qzh(n + 5, 0);
	for (int i = 0; i < m;i++)
	{
		int x;
		cin >> x;
		qzh[x]++;
	}
	for (int i = n;i >= 1;i--)
	{
		qzh[i] += qzh[i + 1];
		a[i].b+=qzh[i];
	}
	int ans = 0,max0=-1,max1=-1;
	for (int i = n;i >= 1;i--)
	{
		if(a[i].a==1)
		{
			max1 = max(max1, a[i].b);
			if(a[i].b<max0)
			{
				ans++;
			}
		}
		else if(a[i].a==0)
		{
			max0 = max(max0, a[i].b);
			if(a[i].b<max1)
			{
				ans++;
			}
		}
	}
	cout << n - ans << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}

	return 0;
}