#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;cin>>n;
	int a[100];
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	int k;cin>>k;
	a[n]=k;
	sort(a,a+n+1);
	for(int i = 0;i < n+1;i++)
	{
		cout<<a[i]<<" ";
	}

	return 0;
}