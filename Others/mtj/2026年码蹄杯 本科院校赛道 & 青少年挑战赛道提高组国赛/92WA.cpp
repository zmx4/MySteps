#include<bits/stdc++.h>
using namespace std;
#define int long long

//9
const int N = 3e5+10,M = 1e6+10;
bool np[M];
int pri[M];
void init()
{
	int k = 0;
	for(int i = 1;i <= M;++i)
	{
		np[i] = 0;
	}
	for(int i = 2;i <= M;++i)
	{
		if(!np[i])
		{
			for(int j = 2*i;j <= M;j+=i)
			{
				np[j]=1;
			}
		}
	}
}
int f[N];
struct edge{
	int u,v,w;
};
int find(int x)
{
	if(f[x]==x)return x;
	return find(f[x]);
}
void unite(int x,int y)
{
	int xx = find(x);
	int yy = find(y);
	f[xx]=yy;
}
void solve()
{
	int n;
	cin >> n;
	init();
	vector<int> a(n+1);
	bool flag = 0;
	int ans = 0;
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
		if(a[i]==1)flag = 1;
		f[i]=i;
		int temp = INT_MAX;
		for(int j = i - 1;j > 0;++j)
		{
			int x = gcd(a[i],a[j]);
			if(!np[x]&&x!=1)
			{
				temp = min(temp,(i - j)*x);
			}
			if(i - j > temp)break;
		}
		if(i!=1)ans = max(ans,temp);
	}
	if(ans==INT_MAX||flag)cout << -1 << endl;
	else cout << ans << endl;
}
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
