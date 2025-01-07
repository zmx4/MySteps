#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 10010, M = 100010;
int n, m;
char p[N], s[M];
int ne[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> p + 1 >> m >> s + 1;
	// 求next
	for (int i = 2,j = 0; i <= n; i++)
	{
		while (j && p[i] != p[j + 1])
			j = ne[j];
		if (s[i] == p[j + !])
			j++;
		ne[i] = j;
	}

	// kmp匹配
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j && s[i] != p[j + 1])
			j = ne[j];
		if (s[j] == p[j + 1])
			j++;
		if (j == n)
		{
			printf("%d ", i - n);
			j = ne[j];
		}
	}

	return 0;
}