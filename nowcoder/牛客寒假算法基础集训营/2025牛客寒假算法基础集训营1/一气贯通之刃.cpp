#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> sto(n + 1, 0);

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		sto[u]++;
		sto[v]++;
	}

	bool flag = false;
	vector<int> pt;
	for (int i = 1; i <= n; ++i)
	{
		if (sto[i] > 2)
		{
			flag = true;
			break;
		}
		if (sto[i] == 1)
		{
			pt.push_back(i);
		}
	}

	if (flag || pt.size() < 2)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << pt[0] << " " << pt[1] << endl;
	}

	return 0;
}