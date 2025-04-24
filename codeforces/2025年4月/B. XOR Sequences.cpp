#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int x, y;
	cin >> x >> y;
	bitset<32> m(x), n(y);
	bool f1 = false, f2 = false;
	int ans = 0;				
	int cnt = 0;
	for (int i = 0; i <= 31; i++)
	{
		if(m[i]!=n[i])
		{
			cout << (1LL << i) << endl;
			break;
		}
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