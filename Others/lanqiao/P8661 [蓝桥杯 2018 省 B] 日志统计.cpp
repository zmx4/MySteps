#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
int n,d,k;
unordered_map<int,vector<int>> mp;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n >> d >> k;
	for (int i = 1; i <= n; i++)
	{
		int x,y;
		cin >> x >> y;
		mp[y].push_back(x);
	}
	vector<int> ans;
	//ma[id]=time
	for(auto &i : mp)
	{
		sort(i.second.begin(), i.second.end());
		int id = i.first;
		int len = i.second.size();
		for (int j = 0; j < len; j++)
		{
			int x = i.second[j];
			auto it = lower_bound(i.second.begin(), i.second.end(), x + d);
			int cnt = it - (i.second.begin() + j);
			if (cnt >= k)
			{
				ans.push_back(id);
				break;
			}
		}
	
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] <<endl;
	}
	cout << endl;

	return 0;
}