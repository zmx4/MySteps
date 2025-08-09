#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N = 3e5+10;
int g[3][N];
bool vis[3][N];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int n;
void bfs(int x,int y)
{
	int cnt = 0;
	queue<pair<int,int>>q;
	q.push({x,y});
	vis[x][y]=1;
	while(!q.empty())
	{
		auto [xx,yy] = q.front();
		q.pop();
		for(int i = 0;i < 4;i++)
		{
			int tx = xx+dx[i],ty = yy + dy[i];
			if(tx>=1&&tx<=2&&ty>=1&&ty<=n&&!vis[tx][ty]&&g[tx][ty]==g[x][y])
			{
//				cout<<tx<<" "<<ty<<endl;
				q.push({tx,ty});
				vis[tx][ty]=1;
			}
		}
	}
	
//	return cnt;
}
signed main( )
{
	cin>>n;
	for(int i = 1;i <= n;i++){
		char x;cin>>x;
		g[1][i]=x-'0';
//		cout<<g[1][i]<<endl;
	}
	for(int i = 1;i <= n;i++){
		char x;cin>>x;
		g[2][i]=x-'0';
//		cout<<g[2][i]<<endl;
	}
//	cout<<1<<endl;
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
//		cout<<1<<endl;
		if(!vis[1][i])
		{
			ans++;
			bfs(1,i);
//			cout<<1<<" "<<i<<endl;
		}
		if(!vis[2][i])
		{
			ans++;
			bfs(2,i);
//			cout<<2<<" "<<i<<endl;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
