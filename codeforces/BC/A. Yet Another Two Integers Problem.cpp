#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	ll a, b;cin>>a>>b;
	ll diff = abs(a - b);
	ll ans = 0;
	if(diff == 0)
	{
		cout<<0<<endl;
		return;
	}
	if(diff % 10 == 0)
	{
		ans = diff / 10;
	}
	else
	{
		ans = diff / 10 + 1;
	}
	cout<<ans<<endl;
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