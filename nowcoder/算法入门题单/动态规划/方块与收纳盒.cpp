#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	int n;
	cin >> n;
	ll f[100];
	f[0] = 1, f[1] = 1;
	for (int i = 2; i <= 100; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}
	cout << f[n] << endl;
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