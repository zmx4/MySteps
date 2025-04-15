#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n, m, l, r;
	cin >> n >> m >> l >> r;
	int al = l, ar ;
	ar = m + al;
	if(ar < 0)
	{
		int diff = abs(ar);
		ar = 0;
		al = al + diff;
	}
	cout << al << " " << ar << endl;
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