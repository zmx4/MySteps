#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int qp[] = {0,1, 2, 3, 4, 5, 6, 7, 8, 9};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	int ans = 0;
	do
	{
		for (int i = 1; i <= 7; i++)
		{
			int x = 0;
			for (int pos = 1; pos <= i; pos++)
			{
				x = x * 10 + qp[pos];
			}
			for (int j = i + 1; j <= 8; j++)
			{
				int y = 0;
				for (int pos = i + 1; pos <= j; pos++)
				{
					y = y * 10 + qp[pos];
				}
				int z = 0;
				for (int pos = j + 1; pos <= 9; pos++)
				{
					z = z * 10 + qp[pos];
				}
				if (z != 0 && y % z == 0 && x + y / z == n)
					ans++;
			}
		}
	} while (next_permutation(qp+1,qp+10));
	cout << ans << endl;

	return 0;
}