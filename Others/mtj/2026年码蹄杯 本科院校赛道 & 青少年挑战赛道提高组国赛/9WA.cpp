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
	vector<edge> e; 
	bool flag = 0;
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
		if(a[i]==1)flag = 1;
		f[i]=i;
		for(int j = 1;j <i;++j)
		{
			int x = gcd(a[i],a[j]);
			if(!np[x]&&x!=1)
			{
				e.push_back({i,j,(i-j)*x});
//				cout <<i<<" "<<j<< " "<<e.back().w << endl;
			}
		}
	}
	if(flag)
	{
		cout << -1 << endl;
	}
	sort(e.begin(),e.end(),[](edge a,edge b){
		return a.w<b.w;
	});
	int cnt = 0;
	int ans =0;
	for(auto eg:e)
	{
		int x = find(eg.u);
		int y = find(eg.v);
		if(x!=y)
		{
			cnt++;
			unite(x,y);
			ans=max(ans,eg.w);
		}
	}
	if(cnt==n-1)cout << ans << endl;
	else cout << -1 << endl;
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
