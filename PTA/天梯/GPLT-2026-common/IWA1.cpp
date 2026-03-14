#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
int f[N];
int find(int x)
{
	return f[x] == x ? x : find(f[x]);
}
void merge(int a,int b)
{
	int x = find(a),y = find(b);
	f[a] = y;
}
void solve()
{
	int m,n;
	cin >> m >> n;
	for(int i = 1;i <= n;i++)f[i] = i;
	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1;
//	cin >> T;
	while (T--)
	{
		solve();
	}
}
