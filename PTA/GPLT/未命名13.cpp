#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int N = 1005;
int g[N][N],row[N],coal[N];
bool rm[N][N];
bool fx[N],fy[N];
signed main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i  = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)cin>>g[i][j];
	while(k--)
	{
		int maxxn = INT_MIN,maxxpos = -1,maxyn = INT_MIN,maxypos = -1;
		for(int i = 1; i <= n; i++)
			{
				int sum = 0;
				for(int j = 1; j <= m; j++)
					{
						if(!rm[i][j])sum+=g[i][j];
					}
				row[i]=sum;
				if(row[i]>=maxxn && !fx[i])
					{
						maxxn = row[i];
						maxxpos = i;
					}
				}
			for(int j = 1; j <= m; j++)
				{
					int sum = 0;
					for(int i = 1; i <= n; i++)
					{
						if(!rm[i][j])sum+=g[i][j];
					}
					coal[j]=sum;
					if(coal[j]>=maxyn && !fy[j])
					{
						maxyn = coal[j];
						maxypos = j;
					}
				}
			for(int i = 1; i <= n; i++)rm[i][maxxpos]=true,g[i][maxxpos]=0;
			for(int j = 1; j <= m; j++)rm[maxypos][j]=true,g[maxypos][j]=0;
		}
	vector<int>ans[n];
	for(int i = 1; i <= n; i++)
		{
			bool flag = false;
			for(int j = 1; j <= m; j++)
				{
					if(!rm[i][j])
					{
						cout<<g[i][j];
						flag = true;
					}
					if(j!=m&&!rm[i][j])cout<<" ";
				}
			if(flag)cout<<endl;
		}
	
}