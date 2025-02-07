#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(), a.end());
	if(n==1)
	{
		cout<<"YES"<<endl;
		return;
	}
	for(int i=1;i<n;i++)
	{
		if(a[i] - a[i-1] > 1)
		{
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
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