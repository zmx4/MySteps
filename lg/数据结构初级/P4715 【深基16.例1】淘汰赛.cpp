#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	ll n;
	cin >> n;
	n = 1<<n;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		q.push({x, i});
	}
	while (q.size() > 2)
	{
		auto a = q.front();
		q.pop();
		auto b = q.front();
		q.pop();
		if (a.first > b.first)
		{
			//cout << a.second + 1 << " " << b.second + 1 << endl;
			q.push({a.first, a.second});
		}
		else
		{
			//cout << b.second + 1 << " " << a.second + 1 << endl;
			q.push({b.first, b.second});
		}
	}
	auto a = q.front();
	q.pop();
	auto b = q.front();
	q.pop();
	if (a.first > b.first)
	{
		cout << b.second + 1 << endl; 
	}
	else
	{
		cout << a.second + 1 << endl;
	}
	return 0;
}