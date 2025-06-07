#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define int long long
using ll = long long;
char g[1010][1010];
int dx[]={0,0,1,-1},dy[] = {-1 ,1, 0, 0};
bool vis[1010][1010];
int dis[1010][1010];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int h,w,n;
	cin>>h>>w>>n;
	vector<pair<int,int>>target(10);
	int sx = -1,sy = -1;
	for(int i = 1;i <= h;i++)
	{
		for(int j = 1;j <= w;j++)
		{
			cin>>g[i][j];
			if(g[i][j]>='1'&&g[i][j]<='9')target[g[i][j]-'0'] = {i,j};
			else if(g[i][j]=='S')sx = i,sy = j;
		}
	}
//	cout<<target[1].first<<endl;
	int d = 0;
	for(int j = 1;j <= n;j++)
	{
//		cout<<"qwq"<<endl;
		queue<pair<int,int>>q;
		q.push({sx,sy});
//		cout<<q.size()<<endl;
		memset(dis,0,sizeof dis);
		memset(vis,0,sizeof vis);
		vis[sx][sy]=1;
		while(!q.empty())
		{
			
			auto [x , y] = q.front();
			q.pop();
			if(x == target[j].first&&y == target[j].second)
			{
				d+=dis[x][y];
				sx = x,sy = y;
//				cout<<x<<" "<<y<<endl;
				break;
			}
			
			for(int i = 0;i < 4;i++)
			{
				
				int nx = x + dx[i],ny = y + dy[i]; 
				if(nx>=1&&nx<=h&&ny>=1&&ny<=w&&g[nx][ny]!='X'&&!vis[nx][ny])
				{
//					cout<<1<<endl;
					q.push({nx,ny});
					vis[nx][ny]=1;
					dis[nx][ny]=dis[x][y]+1;
				}
			}
		}
	}
	cout<<d<<endl;
}
