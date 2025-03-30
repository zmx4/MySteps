#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	int n;cin>>n;
	if(n%2==1&&(n-3)%4==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

signed main()
{
	int t;cin>>t;
	cin.ignore();
	while(t--)
	{
		solve();
	}
}