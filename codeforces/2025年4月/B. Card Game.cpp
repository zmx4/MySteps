#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
int games(int a,int b)
{
	if(a>b)
		return 1;
	else if(a == b)
		return 0;
	else
		return -1;
}
void solve()
{

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = 0;
	if(games(a,c)+games(b,d) > 0)
		ans+=2;
	if(games(a,d)+games(b,c) > 0)
		ans+=2;
	
	
	cout << ans << endl;
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