#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
#define int long long
void solve()
{
	int n;cin>>n;
	map<int,int> mp;
	for(int i = 1; i <= n; i++)
	{
		int x;cin>>x;
		mp[x]++;
	}
	int cnt = 0;
	for(auto [x,y]:mp)
	{
		if(y > 1) cnt += y - 1;
	}
	cout << n-((cnt+1)/2)*2 << endl;
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