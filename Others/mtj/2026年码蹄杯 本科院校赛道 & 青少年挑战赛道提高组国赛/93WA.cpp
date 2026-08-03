#include<bits/stdc++.h>
using namespace std;
#define int long long

//9
const int N = 3e5+10,M = 1e6+10;
int a[N];
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

void solve()
{
	int n;
	cin >> n;
	
	for(int i = 1;i <= n;++i)cin >> a[i];
	int l = 1,r = n;
}
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	init();
	while(T--)
	{
		solve();
	}
	
	return 0;
}
