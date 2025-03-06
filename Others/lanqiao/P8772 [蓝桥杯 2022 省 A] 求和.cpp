#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	ll n;cin>>n;
	vector<ll> a(n+1);
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	sort(a.begin(), a.end());
	vector<ll> pre(n+2,0);
	for(int i = 1; i <= n; i++)
		pre[i] = pre[i-1]+a[i];
	ll ans = 0;
	for(int i = 1; i <= n; i++)
		ans += a[i]*(pre[n]-pre[i]);
	cout<<ans<<endl;

	return 0;
}