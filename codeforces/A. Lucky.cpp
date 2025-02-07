#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int fi = n / 1000, se = n % 1000;
	int sumfi = 0, sumse = 0;
	while (fi)
	{
		sumfi += fi % 10;
		fi /= 10;
	}
	while (se)
	{
		sumse += se % 10;
		se /= 10;
	}
	if (sumfi == sumse)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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