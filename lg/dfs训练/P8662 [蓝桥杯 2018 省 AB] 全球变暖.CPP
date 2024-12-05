#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int p[N][N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;cin>>n;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			cin>>p[i][j];
		}
	}
	return 0;
}