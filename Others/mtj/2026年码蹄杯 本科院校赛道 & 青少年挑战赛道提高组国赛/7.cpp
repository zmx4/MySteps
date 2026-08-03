#include<bits/stdc++.h>
using namespace std;
#define int long long

//7
void solve()
{
	int n,x;
	cin >> n >> x;
	unordered_set<int> im;
	vector<int> ans;
	ans.reserve(n);
	for(int i = 1;i <= n;++i)
	{
		if(!im.count(i))
		{
			ans.push_back(i);
			if(x - i <= n)im.insert(x - i);
		}
	}
	cout << ans.size() << endl;
	for(auto x:ans)cout << x << " ";
	cout << endl;
}
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}
	
	
	return 0;
}
