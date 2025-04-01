#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	map<int,int> mp;
	for (int i = 1; i <= 7;i++)
	{
		int x;cin >> x;
		mp[x]++;
	}
	bool fullHouse = false;
	for (auto p : mp)
	{
		for (auto q : mp)
		{
			if (p.first != q.first && p.second >= 3 && q.second >= 2)
			{
				fullHouse = true;
				break;
			}
		}
		if (fullHouse)
			break;
	}

	if (fullHouse)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}