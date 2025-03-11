#include <iostream>
#include <set>
#include <vector>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<set<int>> dishes(n);
	for (int i = 0; i < n; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			int things;
			cin >> things;
			dishes[i].insert(things);
		}
	}
	int q;
	cin >> q;
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		int cnt = 0;
		for (auto &dish : dishes)
		{
			if (dish.count(x) && dish.count(y))
			{
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}