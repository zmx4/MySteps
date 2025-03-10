#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int n, ru[1005], chu[1005], f[1005], ans = 0;
vector<vector<int>> e(1005, vector<int>(1005));

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a, b;cin>>a>>b;
		ru[i]=a,chu[i]=b;
		e[a].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!chu[i])
		{
			queue<int> q;
			q.push(i);
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				f[u]++;
				ans=max(ans,f[u]);
				for(auto v:e[u])
				{
					f[v]=max(f[v],f[u]);
					chu[v]--;
					if(!chu[v])
						q.push(v);
				}
			}
		}
	}
	cout<<ans<<endl;


	return 0;
}