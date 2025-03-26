#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0,0};
void solve()
{
	int n, m;
	cin>>n>>m;
	char a[n + 1][m + 1];
	bool vis[n + 1][m + 1];
	int dis[n + 1][m + 1];
	memset(dis, 0, sizeof(dis));
	memset(vis, false, sizeof(vis));
	int sx = 0, sy = 0, tx = 0, ty = 0;
	for (int i = 1; i <= n;i++)
		for (int j = 1; j <= m;j++)
		{
			cin >> a[i][j];
			if(a[i][j]=='s')
				sx = i, sy = j;
			else if(a[i][j]=='t')
				tx = i, ty = j;
		}
	queue<pair<int, int>> q;
	q.push({sx, sy});
	vis[sx][sy] = 1;
	bool flag = 0;
	while(!q.empty())
	{
		auto [x, y] = q.front();
		q.pop();
		if(x==tx&&y==ty)
		{
			flag = 1;
			break;
		}
		for (int i = 0; i < 4;i++)
		{
			int nx = dx[i] + x, ny = dy[i] + y;
			if(nx<1||ny<1||nx>n||ny>m||vis[nx][ny]||a[nx][ny]=='x')
				continue;
			vis[nx][ny] = 1;
			dis[nx][ny] = dis[x][y] + 1;
			q.push({nx, ny});
		}
	}
	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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