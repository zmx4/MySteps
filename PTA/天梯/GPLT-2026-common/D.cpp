#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> a(n+1);
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] % 2 ==0)ans += a[i];
	}
	cout << ans;
	
}
