#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	int a = min(n/2, m);
	int r = n + m - 3*a;
	if(r>=k)
	{
		cout<<a<<endl;
		return;
	}
	k -= r;
	a -= (k+2)/3;
	cout<<a<<endl;
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