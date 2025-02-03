#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		// n: 宽(列数)，m: 高(行数)
		cin >> n >> m;
		// 1-indexed 建立矩阵
		vector<vector<int>> demand(m + 1, vector<int>(n + 1, 0));
		vector<long long> rowSum(m + 1, 0), colSum(n + 1, 0);
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> demand[i][j];
				rowSum[i] += demand[i][j];
				colSum[j] += demand[i][j];
			}
		}

		long long total = 0;
		for (int i = 1; i <= m; i++)
		{
			total += rowSum[i];
		}
		long long half = (total + 1) / 2;
		long long cum = 0;
		int medRow = 1;
		for (int i = 1; i <= m; i++)
		{
			cum += rowSum[i];
			cout << cum << endl;
			if (cum >= half)
			{
				medRow = i;
				break;
			}
		}
		//cout << half << " ";
		total = 0;
		for (int j = 1; j <= n; j++)
		{
			total += colSum[j];
		}
		half = (total + 1) / 2;
		cum = 0;
		int medCol = 1;
		for (int j = 1; j <= n; j++)
		{
			cum += colSum[j];
			if (cum >= half)
			{
				medCol = j;
				break;
			}
		}
		cout<<medRow<<" "<<medCol<< endl;
		//cout << half << endl;
		long long ans = 0;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				ans += (long long)demand[i][j] * (abs(i - medRow) + abs(j - medCol));
			}
		}
		cout << ans << "\n";
	}

	return 0;
}