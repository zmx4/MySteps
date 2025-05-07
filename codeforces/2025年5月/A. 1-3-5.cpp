#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
vector<int> f(105);
void init()
{
	f[0] = 0;
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i <= 105; i++)
	{
		f[i] = f[i - 1] + 1;
		f[i] = min(f[i], f[i - 3]);
		if (i >= 5)
			f[i] = min(f[i], f[i - 5]);
	}
}
void solve()
{
	int n;
	cin >> n;
	cout << f[n] << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
	init();
	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}