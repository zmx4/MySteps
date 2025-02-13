#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;



signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n, m;
	while(cin>>n>>m)
	{
		int bposx, bposy;
		vector<vector<int>> a(n, vector<int>(m));
		for(int i=0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				char x;
				cin>>x;
				if(x=='.')a[i][j] = 0;
				else if(x=='#')a[i][j] = 1;
				else if(x=='S')
				{
					a[i][j] = 2;
					bposx = i;
					bposy = j;
				}
				else if(x=='E')
				{
					a[i][j] = 3;
				}
			}
		}
		queue<pair<int, int>> q;
		q.push({bposx, bposy});
		vector<vector<int>> vis(n, vector<int>(m, 0));
		vis[bposx][bposy] = 1;
		int dx[] = {0, 0, 1, -1};
		int dy[] = {1, -1, 0, 0};
		int flag = 0;
		while(!q.empty())
		{
			auto [x, y] = q.front();
			q.pop();
			for(int i=0;i<4;i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && a[nx][ny]!=1)
				{
					if(a[nx][ny]==3)
					{
						flag = 1;
						break;
					}
					vis[nx][ny] = 1;
					q.push({nx, ny});
				}
			}
			if(flag)break;
		}
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}

	return 0;
}