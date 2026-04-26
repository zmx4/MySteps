#include<bits/stdc++.h>
using namespace std;
int n,m;
int getres(const string &s1,const string &s2)
{
	int res = 0;
	for(int i = 0 ;i < m;++i)
	{
		if(s1[i]!=s2[i])res++;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	
	cin >> n >> m;
	long long ans = 0;
	vector<string> a(n+1);
	vector<vector<long long>> g(m+1,vector<long long>(30));
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
		for(int j = 0;j < m;++j)
		{
			int c = a[i][j] - 'a';
			for(int k = 0;k < 26;k++)
			{
				if(c == k)continue;
				ans += g[j][k];
			}
			g[j][c]++;
		}
	}
//	long long ans = 0;
//	for(int i = 1;i <= n;++i)
//	{
//		for(int j = i + 1;j <= n;++j)
//		{
//			ans += getres(a[i],a[j]);
//		}
//	}
	cout << ans << endl;
	
	return 0;
}
