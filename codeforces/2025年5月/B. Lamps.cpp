#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n;
	cin>>n;
	map<int,priority_queue<int>> mp;
	for(int i=0;i<n;i++)
	{
		int a, b;
		cin>>a>>b;
		mp[a].push(b);
	}
	ll ans = 0;
	for(auto [a, b]:mp)
	{
		int cnt = 0;
		while(!b.empty() && cnt < a)
		{
			int x = b.top();
			b.pop();
			ans+=x;
			cnt++;
		}
	}
	cout<<ans<<endl;
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