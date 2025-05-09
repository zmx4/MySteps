#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1005;
int g[N][N];
bool vis[N][N];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve()
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin >> g[i][j];
		}
	}

	// 重置访问标记
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			vis[i][j] = false;

	auto bfs = [&](int x, int y) -> int
	{
		int cnt = g[x][y];
		queue<pair<int, int>> q;
		q.push({x, y});
		vis[x][y] = true;
		while (!q.empty())
		{
			auto [u, v] = q.front();
			q.pop();
			for (int d = 0; d < 4; d++)
			{
				int nx = u + dx[d], ny = v + dy[d];
				if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && g[nx][ny] > 0)
				{
					vis[nx][ny] = true;
					cnt += g[nx][ny];
					q.push({nx, ny});
				}
			}
		}
		return cnt; // <<< 一定要返回 cnt
	};
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(!vis[i][j] && g[i][j] > 0)
			{
				ans = max(ans, bfs(i, j));
			}
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