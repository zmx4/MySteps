#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	vector<int> q;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		q.push_back(i);
	int pos = 0;
	vector<int> ans;
	while (!q.empty())
	{
		pos = (pos + m - 1) % q.size();
		ans.push_back(q[pos]);
		q.erase(q.begin() + pos);
	}
	for (int i = 0; i < ans.size(); i++)
	{
		if (i == 0)
			cout << ans[i];
		else
			cout << " " << ans[i];
	}
	cout << endl;
	return 0;
}