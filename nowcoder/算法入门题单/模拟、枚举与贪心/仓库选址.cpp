#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int manhattanDistance(int x1, int y1, int x2, int y2)
{
	return std::abs(x1 - x2) + std::abs(y1 - y2);
}

void solve()
{
	int n, m;
	cin >> n >> m;
	int a[n + 3][m + 3];
	memset(a, 0, sizeof(a));
	ll rowSum[n + 3], colSum[m + 3];
	memset(rowSum, 0, sizeof(rowSum));
	memset(colSum, 0, sizeof(colSum));
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			rowSum[i] += a[i][j];
			colSum[j] += a[i][j];
		}
	}
	ll sum = 0;
	for (int i = 1; i <= m; i++)
	{
		sum += rowSum[i];
	}
	ll half = (sum + 1) / 2;

	ll cum = 0;
	int row = 1;
	for (int i = 1; i <= m; i++)
	{
		cum += rowSum[i];
		//cout << cum << endl;
		if (cum >= half)
		{
			row = i;
			break;
		}
	}
	cum = 0;
	int col = 1;
	sum = 0;
	for (int j = 1; j <= n;j++)
	{
		sum += colSum[j];
	}
	for (int j = 1; j <= n; j++)
	{
		cum += colSum[j];
		if (cum >= half)
		{
			col = j;
			break;
		}
	}
	// cout << half << endl;
	ll ans = 0;
	//cout << row << " " << col << endl;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans += (ll)a[i][j] * (abs(i - row) + abs(j - col));
		}
	}
	cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}