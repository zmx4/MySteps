#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;
	cin >> n;
	map<string, unordered_set<string>> mp;
	int treasureIsland = 0;
	while (n--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			string island, treasure;
			cin >> island >> treasure;
			if (mp[island].empty())
			{
				treasureIsland++;
			}
			mp[island].insert(treasure);
		}
		else if (op == 2)
		{
			string island;
			cin >> island;
			cout << mp[island].size() << endl;
		}
		else if (op == 3)
		{
			string island, treasure;
			cin >> island >> treasure;
			if (mp.find(island) != mp.end() && mp[island].find(treasure) != mp[island].end())
			{
				cout << "1" << endl;
			}
			else
			{
				cout << "0" << endl;
			}
		}
		else if (op == 4)
		{
			cout << treasureIsland << endl;
		}
	}

	return 0;
}