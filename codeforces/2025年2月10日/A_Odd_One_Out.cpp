#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(a!=b && a!=c)
		cout<<a<<endl;
	else if(b!=a && b!=c)
		cout<<b<<endl;
	else
		cout<<c<<endl;
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