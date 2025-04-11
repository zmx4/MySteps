#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
int g[22][22];
int sx, sy, fx, fy;
bool vis[22][22];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int N, M, T;
int ans;
void dfs(int x,int y)
{
	if(x==fx&&y==fy)
	{
		ans++;
		return;
	}
	for (size_t i = 0; i < 4; i++)
	{
		int tx = dx[i] + x, ty = dy[i] + y;
		if (tx >= 1 && tx <= N && ty >= 1 && ty <= M && !vis[tx][ty] && g[tx][ty] != 1)
		{
			vis[tx][ty] = 1;
			dfs(tx, ty);
			vis[tx][ty] = 0;
		}
	}
	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	
	cin >> N >> M >> T;
	cin >> sx >> sy >> fx >> fy;
	for (int i = 0; i < T;i++)
	{
		int x, y;
		cin >> x >> y;
		g[x][y] = 1;
	}
	// queue<pair<int,int>> q;
	// int cnt = 0;
	// q.push({sx,sy});
	// vis[sx][sy] = 1;
	// while(!q.empty())
	// {
		// auto [x, y] = q.front();
		// q.pop();
		// for (int i = 0; i < 4;i++)
		// {
			// int tx = dx[i] + x, ty = dy[i] + y;
			// if(tx>=1&&tx<=N&&ty>=1&&ty<=M&&!vis[tx][ty]&&g[tx][ty]!=1)
			// {
				// vis[tx][ty] = 1;
				// if(tx!=fx&&ty!=fy)
					// q.push({tx, ty});
				// else
					// cnt++;
			// }
		// }
	// }
	//cout << cnt << endl;
	vis[sx][sy] = 1;
	dfs(sx, sy);
	cout << ans << endl;
	return 0;
}