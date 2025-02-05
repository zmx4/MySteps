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
	vector<int> a(n);
	for(int &i:a)
		cin >> i;
	sort(a.begin(),a.end(),greater<int>());
	int ans=0;
	while(a.size()>1)
	{
		int x=a.back();
		a.pop_back();
		int y=a.back();
		a.pop_back();
		ans+=x*y;
		a.push_back(x+y);
	}
	cout << ans << endl;
	return 0;
}