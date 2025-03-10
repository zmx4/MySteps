#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<int> b=a;
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for (int i = 0; i < n;i++)
	{
		auto it=lower_bound(b.begin(),b.end(),a[i]);
		cout<<distance(b.begin(),it) + 1<<" ";
	}
	cout<<endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}