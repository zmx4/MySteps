#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
const int N = 100010,M = 2 * N;
int h[N],e[M],ne[M],idx;
bool st[N];

int ans = N;

void add(int a,int b)
{
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}



int dfs(int u)
{
	st[u] = true;
	
	int sum = 1, res = 0;
	for(int i = h[u];i!=-1;i = ne[i])
	{
		int j = e[i];
		if(!st[j]) 
		{
			int s = dfs(j);
			res = max(res,s);
			sum += s;
		}
	}

	res = max(res,n - sum);

	ans = min(ans,res);
	return sum;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	memset(h,-1,sizeof h);

	cin>>n;

	for(int i = 0;i<n - 1;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b),add(b,a);
	}
	dfs(1);

	cout<<ans<<endl;
	return 0;
}