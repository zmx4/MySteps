#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n,k;
	cin >> n >> k;
	vector<int> a(n+1);
	for(int i = 1;i <= n;++i)cin >> a[i];
	int ans = 0;
	int xx = n / k;
	for(int i = k;i <= n;i += k)
	{
		ans += a[i];
//		cout << i << " ";
	}
	cout << ans << endl;
	
	return 0;
}
