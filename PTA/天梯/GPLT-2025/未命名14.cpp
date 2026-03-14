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
	int sum = 0;
	cin>>n>>m>>k;
	for(int i  = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)cin>>g[i][j],sum+=g[i][j];
	while(k--)
	{
		int ii,jj;
		int sumi = 0;
		for(int i = 1;i <= n;i++)
		{
			
			for(int j = 1;j <= m;j++)
			{
				sumi+=g[i][j];
			}
			if(sumi*2>sum)
			{
				ii = i;
				break;
			}
		}
		int sumj = 0;
		for(int j = 1;j <= m;j++)
		{
			
			for(int i = 1;i <= n;i++)
			{
				sumj+=g[i][j];
			}
			if(sumj*2>sum)
			{
				jj = j;
				break;
			}
		}
		for(int i = 1;i <= n;i++)sum-=g[jj][i],rm[jj][i] = true,g[jj][i] = 0;
		for(int j = 1;j <= n;j++)sum-=g[j][ii],rm[j][ii] = true,g[j][ii] = 0;
	}
	for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				{
					if(!rm[i][j])cout<<g[i][j]<<" ";
				}
			cout<<endl;
		}
}