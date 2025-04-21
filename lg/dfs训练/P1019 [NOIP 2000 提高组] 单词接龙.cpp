#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
vector<string> a;
int n;
char st;
int ans = -1;
string str = "";
int vis[25];

void dfs(const string &s)
{
	ans = max((int)s.size(), ans);
	for (int i = 0; i < n;i++)
	{
		if(vis[i] < 2)
		{
			int len = min(a[i].size(),s.size());
			for(int j = 1; j < len; j++)
			{
				if(s.substr(s.length()-j)==a[i].substr(0,j))
				{
					vis[i]++;
					string nxt = s + a[i].substr(j);
					dfs(nxt);
					vis[i]--;
				}
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	
	cin >> n;
	a.resize(n);
	for(auto &i:a)
		cin >> i;
	cin >> st;
	for (int i = 0; i < n;i++)
	{
		vis[i] = 1;
		if(a[i][0]==st)dfs(a[i]);
		vis[i] = 0;
	}
	cout << ans << endl;
	return 0;
}