#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	vector<pair<int, int>> v1, v2;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		v1.push_back({a, b});
	}
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		v2.push_back({a, b});
	}
	map<int, int,greater<int>> mp;
	for(auto i:v1)
		for(auto j:v2)
			mp[i.second + j.second] += i.first * j.first;
	bool flag = false;
	stringstream ans;
	for(auto &i:mp)
	{
		if(i.second)
		{
			flag = true;
			ans << i.second << " " << i.first << " ";
		}
	}
	if(flag)
		cout << ans.str().substr(0, ans.str().size() - 1) << endl;
	else
		cout << "0 0" << endl;

	return 0;
}