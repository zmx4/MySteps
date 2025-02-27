#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;


void solve()
{
	ll n;
	cin>>n;

	ll ans = 2;
	ll fi = 1, se = 2;
	for (int i = 3; se < n;i++)
	{
		ll temp = se;
		se += fi;
		fi = temp;
		if(se%2==0 && se < n)
		{
			ans += se;
		}
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