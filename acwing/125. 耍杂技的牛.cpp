#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;cin>>n;
	vector<pair<int,ll>> a(n+1);
	for (int i = 1; i <= n; i++) cin>>a[i].first>>a[i].second;
	sort(a.begin()+1,a.end(),[&](pair<int,ll> a,pair<int,ll> b){return a.first + a.second<b.first + b.second;});
	ll danger = 0,sumwight = 0;
	sumwight += a[1].first;
	danger -= a[1].second;
	for (int i = 2; i <= n; i++)
	{
		danger = max(danger, sumwight - a[i].second);
		sumwight += a[i].first;
	}
	cout<<danger<<endl;


	return 0;
}