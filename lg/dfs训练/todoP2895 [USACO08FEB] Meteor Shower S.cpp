#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 310;
int a[MAXN][MAXN];
int M;
bool vis[MAXN][MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = 0x3f3f3f3f,cnt = 0;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);


	cin >> M;
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> a[i][j];
		}
	}
	queue<pair<int, int>> q;
	q.push({1, 1});







	return 0;
}