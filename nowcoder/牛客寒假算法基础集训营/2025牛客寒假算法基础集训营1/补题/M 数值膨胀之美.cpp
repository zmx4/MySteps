#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n+1);
	vector<pair<int,int>> b;
	multiset<int> st;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b.push_back({a[i],i});
		st.insert(a[i]);
	}
	sort(b.begin(),b.end());
	auto [l,r] = b[0];
	st.extract(l);
	st.insert(l * 2);
	int ans = *st.rbegin() - *st.begin();
	for(auto [_,i] : b)
	{
		if(i>=l&&i<=r) continue;
		//cout << i << " " << l << " " << r << endl;
		for (int j = l - 1; j >= i;j--)
		{
			st.extract(a[j]);
			st.insert(a[j]*2);
			ans = min(ans, *st.rbegin() - *st.begin());
			//cout << j << endl;
		}
		l = min(l, i);
		for (int j = r + 1; j <= i;j++)
		{
			st.extract(a[j]);
			st.insert(a[j]*2);
			ans = min(ans, *st.rbegin() - *st.begin());
			//cout << j << endl;
		}
		r = max(r, i);
		//cout << i << " " << l << " " << r << endl;
	}
	cout << ans;
	return 0;
}