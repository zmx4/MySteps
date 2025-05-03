#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,1,-1};
void solve()
{
	vector<vector<char>> a(9,vector<char>(9));
	for(int i = 1; i <= 8; i++)
	{
		for(int j = 1; j <= 8; j++)
		{
			cin>>a[i][j];
		}
	}

	for (int i = 2;i <= 7;i++)
	{
		for (int j = 2;j <= 7;j++)
		{
			if (a[i][j] == '#')
			{
				int cnt = 0;
				for (int k = 0;k < 4;k++)
				{
					
					int x = i + dx[k],y = j + dy[k];
					if (a[x][y] == '#')
					{
						cnt++;
					}
				}
				if (cnt == 4)
				{
					cout << i << " " << j << endl;
					return;
				}
			}
		}
	}
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