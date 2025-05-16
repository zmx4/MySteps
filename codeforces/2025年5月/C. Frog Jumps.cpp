#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
string s;
int n ;
bool vis[200005];
bool flag = false;

void solve()
{
	flag = false;
	cin >> s;
	n = s.size();
	vector<int> pos(n);
	pos.push_back(0);
	for(int i = 0; i < n; i++)
	{
		if (s[i] == 'R')
		{
			pos.push_back(i+1);
		}
	}
	pos.push_back(s.size() + 1);
	int ans = 0;
	for (int i = 0; i < int(pos.size()) - 1; ++i)
	{
		ans = max(ans, pos[i + 1] - pos[i]);
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