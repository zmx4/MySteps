#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

void solve()
{
	int g[10][10];
	for (int i = 1; i <= 9;i++)
		for (int j = 1; j <= 9;j++)
		{
			cin >> g[i][j];
		}
	bool flag = true;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (g[i][j] < 1 || g[i][j] > 9)
			{
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}
	for (int i = 1; i <= 9 && flag; i++)
	{
		set<int> s;
		for (int j = 1; j <= 9; j++)
		{
			if (s.count(g[i][j]))
			{
				flag = false;
				break;
			}
			else
				s.insert(g[i][j]);
		}
	}
	for (int j = 1; j <= 9; j++)
	{
		set<int> s;
		for (int i = 1; i <= 9; i++)
		{
			if (s.count(g[i][j]))
				flag = false;
			else
				s.insert(g[i][j]);
		}
	}
	for (int i = 1; i <= 7 && flag; i += 3)
	{
		for (int j = 1; j <= 7 && flag; j += 3)
		{
			set<int> s;
			for (int ii = i; ii < i + 3; ii++)
			{
				for (int jj = j; jj < j + 3; jj++)
				{
					if (s.count(g[ii][jj]))
					{
						flag = false;
						break;
					}
					else
						s.insert(g[ii][jj]);
				}
				if (!flag)
					break;
			}
		}
	}
	if(flag)
		cout << 1 << endl;
	else
		cout << 0 << endl;
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