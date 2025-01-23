#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	ll n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum+=a[i];
	}
	ll targetSum = n * (n + 1) / 2;
	if(sum != targetSum)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	sort(a.begin(), a.end());
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += abs(a[i] - (i + 1));
	}

	cout<<ans/2<<endl;

	return 0;
}