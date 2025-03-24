#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int N = 15;
bool row[N], coal[N], dg[N*2], udg[N*2];
bool grid[N][N];
vector<int> ans;
vector<vector<int>> sol;
int n;
void dfs(int u)
{
	if(u==n)
	{
		sol.push_back(ans);
		return;
	}
	for (int i = 0; i < n;i++)
	{
		if(!coal[i]&&!dg[u+i]&&!udg[u-i+n])
		{
			ans[u] = i;
			coal[i] = dg[u + i] = udg[u - i + n] = true;
			dfs(u + 1);
			coal[i] = dg[u + i] = udg[u - i + n] = false;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);


	cin >> n;
	ans.resize(n);
	dfs(0);
	sort(sol.begin(), sol.end(), [](const vector<int> &a, const vector<int> &b)
		 {
        for (int i = 0; i < a.size(); i++) {
            if(a[i] != b[i])
                return a[i] < b[i];
        }
        return false; });
	int total = sol.size();
	int showCount = min(total, 3);
	for (int i = 0; i < showCount; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << sol[i][j] + 1;
			if (j < n - 1)
				cout << " ";
		}
		cout << endl;
	}
	cout << total << endl;

	return 0;
}