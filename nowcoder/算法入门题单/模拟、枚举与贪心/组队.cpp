#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n),cf(n+1);
	for(int &i:a)
		cin >> i;
	sort(a.begin(),a.end());
	/*
	int ans=0;
	for(int i = 0; i < k; i++)
	{
		int temp = 1;
		for(int j = i + 1; j < n; j++)
		{
			if(a[j]-a[i]>k)
				break;
			temp++;
		}
		ans = max(ans, temp);
	}
	cout << ans << endl;
	*/
	for(int i = 0; i < n; i++)
	{
		cf[i+1] = cf[i] + a[i];
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int l = i, r = n;
		while(l < r)
		{
			int mid = (l + r) >> 1;
			if(a[mid] - a[i] <= k)
				l = mid + 1;
			else
				r = mid;
		}
		ans = max(ans, l - i);
	}
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}