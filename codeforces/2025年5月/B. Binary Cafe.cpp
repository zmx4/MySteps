#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n, k;
	cin >> n >> k;
	int maxn = 0;
	int cnt = 0;
	for (int i = 30;i >= 0;i--)
	{
		if (n & (1 << i))
		{
			maxn = i;
			cnt++;
		}
	}
	k = min(k, 30);
	cout<<min(n,(1<<k)-1) + 1<<endl;
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