#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
	return a.first > b.first;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int N, K, S;
	cin >> N >> K >> S;
	vector<pair<int, int>> v, g;
	for (int i = 0; i < N; i++)
	{
		int score, pat;
		cin >> score >> pat;
		if (score < 175)
			continue;
		if (pat < S)
			v.push_back({score, pat});
		else
			g.push_back({score, pat});
	}
	sort(v.begin(), v.end(), cmp);
	sort(g.begin(), g.end(), cmp);

	vector<vector<pair<int, int>>> ans(K);
	for (int i = 0; i < (int)v.size(); i++)
	{
		int idx = i % K;
		if (ans[idx].empty() || ans[idx].back().first != v[i].first)
			ans[idx].push_back(v[i]);
	}

	for (int i = 0; i < (int)g.size(); i++)
	{
		int idx = i % K;
		ans[idx].push_back(g[i]);
	}

	int res = 0;
	for (int i = 0; i < K; i++)
	{
		res += ans[i].size();
	}

	cout << res << endl;
	return 0;
}