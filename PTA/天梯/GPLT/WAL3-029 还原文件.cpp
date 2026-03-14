#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;
const int N = 1e5 + 10;
int n, m;
int a[N];
vector<int> b[110];
int ans[110];
bool st[110];

pair<int, int> findPosition(int idx)
{
	vector<int> &piece = b[idx];
	for (int i = 1; i <= n - piece.size() + 1; ++i)
	{
		bool match = true;
		for (int j = 0; j < piece.size(); ++j)
		{
			if (piece[j] != a[i + j])
			{
				match = false;
				break;
			}
		}
		if (match)
		{
			return {i, idx};
		}
	}
	return {-1, -1};
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j)
		{
			int x;
			cin >> x;
			b[i].push_back(x);
		}
	}

	vector<pair<int, int>> positions;
	for (int i = 1; i <= m; ++i)
	{
		positions.push_back(findPosition(i));
	}

	sort(positions.begin(), positions.end());

	for (int i = 0; i < m; ++i)
	{
		cout << positions[i].second;
		if (i < m - 1)
			cout << " ";
	}
	cout << endl;

	return 0;
}