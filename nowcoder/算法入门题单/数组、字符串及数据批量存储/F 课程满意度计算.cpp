#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int N, M;
	cin>>N>>M;
	int a[M+1];
	memset(a, 0, sizeof(a));
	int n = N;
	while(n--)
	{
		int S;
		cin >> S;
		for(int i=1; i<=S; i++)
		{
			int x;
			cin>>x;
			a[x]++;
		}
	}
	int cnt = 0;
	for(int i=1; i<=M; i++)
	{
		//cout<<a[i]<<endl;
		if(a[i] == N)
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}