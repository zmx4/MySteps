#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;




void solve()
{
	int n, m;cin >> n >> m;
	deque<int> a(n);
	for(auto &i:a)
	{
		string s;
		cin >> s;
		i = s.length();
	}
	int cnt = 0, ans = 0;
	while (!a.empty() && cnt < m)
	{
		if(cnt+a.front()<=m)
		{
			cnt += a.front();
			a.pop_front();
			ans++;
		}
		else
		{
			break;
		}
	}
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