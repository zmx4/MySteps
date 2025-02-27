#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main()
{
	int n;
	cin >> n;

	// 读入距离矩阵
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	// dp[state][i]: 从0出发，经过state中所有点，当前在i点的最短路径长度
	vector<vector<int>> dp(1 << n, vector<int>(n, INF));
	// path[state][i]: 记录在state状态下，到达i点的前一个节点
	vector<vector<int>> path(1 << n, vector<int>(n, -1));

	// 初始状态：只访问节点0
	dp[1][0] = 0;

	for (int state = 1; state < (1 << n); state++)
	{
		// 如果状态中不包含起点0，跳过
		if (!(state & 1))
			continue;

		for (int i = 0; i < n; i++)
		{
			// 如果状态中不包含当前节点i，跳过
			if (!(state & (1 << i)))
				continue;

			// 如果当前在节点0但状态不是只有节点0，跳过（不能回到起点）
			if (i == 0 && state != 1)
				continue;

			// 尝试所有可能的前一个节点j
			for (int j = 0; j < n; j++)
			{
				if (j == i)
					continue; // j不能等于i
				if (!(state & (1 << j)))
					continue; // 状态中必须包含j

				// 前一个状态：从当前状态中去掉节点i
				int prev_state = state & ~(1 << i);
				if (dp[prev_state][j] + a[j][i] < dp[state][i])
				{
					dp[state][i] = dp[prev_state][j] + a[j][i];
					path[state][i] = j; // 记录前一个节点
				}
			}
		}
	}

	// 输出最短Hamilton路径长度
	cout << dp[(1 << n) - 1][n - 1] << endl;

	// 重建路径
	int state = (1 << n) - 1;
	int cur = n - 1;
	vector<int> hamilton_path;
	hamilton_path.push_back(cur);

	while (cur != 0)
	{
		int prev = path[state][cur];
		hamilton_path.push_back(prev);
		state = state & ~(1 << cur); // 从状态中去掉当前节点
		cur = prev;
	}

	// 反转路径（因为我们是从终点往回推的）
	reverse(hamilton_path.begin(), hamilton_path.end());

	// 输出路径
	for (int i = 0; i < hamilton_path.size(); i++)
	{
		cout << hamilton_path[i];
		if (i < hamilton_path.size() - 1)
			cout << " -> ";
	}
	cout << endl;

	return 0;
}