#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int n;
vector<vector<int>> res;
vector<int> cur;

void dfs(int sum, int start)
{
	if (sum == n)
	{
		res.push_back(cur);
		return;
	}
	// 枚举候选数字，从 start 开始，保证数字非降序
	for (int i = start; i < n; i++)
	{
		if (sum + i <= n)
		{
			cur.push_back(i);
			dfs(sum + i, i);
			cur.pop_back();
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n;
	vector<int> a;
	dfs(0,1);
	for (auto &seq : res)
	{
		for (int i = 0; i < seq.size(); i++)
		{
			cout << seq[i] << (i == seq.size() - 1 ? "" : "+");
		}
		cout << endl;
	}
	return 0;
}