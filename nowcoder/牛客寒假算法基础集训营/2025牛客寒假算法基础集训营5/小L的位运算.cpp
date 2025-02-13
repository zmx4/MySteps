#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool check(char a, char b, char c)
{
	return ((a - '0') ^ (b - '0')) == (c - '0');
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n;
	ll x, y;
	cin >> n >> x >> y;

	string a, b, c;
	cin >> a >> b >> c;

	vector<int> pos;
	for (int i = 0; i < n; i++)
	{
		if (!check(a[i], b[i], c[i]))
		{
			pos.push_back(i);
		}
	}

	ll res = 0;
	int cnt = pos.size();

	if (cnt % 2 == 0)
	{
		ll cost1 = (ll)cnt * x;
		ll cost2 = (ll)(cnt / 2) * y;
		res = min(cost1, cost2);
	}
	else
	{
		res = x + min((ll)((cnt - 1) * x), (ll)((cnt - 1) / 2) * y);
	}

	cout << res << endl;
	return 0;
}