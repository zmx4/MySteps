#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int maxw, maxt;
int n;
int w[1005], t[1005], v[1005];
int dp[52][521][521];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin>>maxw>>maxt;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>t[i]>>v[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=maxw;j>=0;j--)
		{
			for(int k=maxt;k>=0;k--)
			{
				dp[i][j][k] = dp[i - 1][j][k];
				if(j>=w[i]&&k>=t[i])
					dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-w[i]][k-t[i]]+v[i]);
			}
		}
	}
	cout<<dp[n][maxw][maxt]<<endl;
	return 0;
}