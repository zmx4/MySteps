#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	ll n;
	cin >> n;
	if(n<=1399)
	{
		cout << "Division 4" << endl;
	}
	else if(n <= 1599)
	{
		cout << "Division 3" << endl;
	}
	else if(n <= 1899)
	{
		cout << "Division 2" << endl;
	}
	else
	{
		cout << "Division 1" << endl;
	}
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