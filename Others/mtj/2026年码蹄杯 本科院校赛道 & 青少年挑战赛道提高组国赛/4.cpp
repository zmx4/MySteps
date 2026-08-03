#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,k;
	cin >> n;
	int ans = (n - 1)/2*n;
//	cout << ans << endl;
	if(n%3==0)
	{
		n;
		cout << ans - n*2/3 << endl;
	}
	else cout << ans << endl;
}
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
	
	
	return 0;
}
