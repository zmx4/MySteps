#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;cin>>n;
	vector<int> a(n),pre(n+1);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		pre[i+1]=pre[i]+a[i];
	}
	int q;cin>>q;
	while(q--)
	{
		int l,r;cin>>l>>r;
		cout<<pre[r]-pre[l-1]<<endl;
	}

	return 0;
}