#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int x, y;
	vector<int> ans;
	int cnt = 0;
	while (cin >> x >> y)
	{
		cnt++;
		if (y == 0)
			break;
		ans.push_back(x * y);
		if (y != 0)
			ans.push_back(y - 1);
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i != ans.size() - 1)
			cout << " ";
	}
	if (ans.size() == 0)
	{
		cout << "0 0" << endl;
	}
}