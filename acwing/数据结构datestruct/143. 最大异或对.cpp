#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N = 4e6 + 10;
int son[N][2], idx;
int a[N];

void insert(int x)
{
	int p = 0;
	for (int i = 30; i >= 0;i--)
	{
		int t = x >> i & 1;
		if(!son[p][t])
			son[p][t] = ++idx;
		p = son[p][t];
	}
}

int query(int n)
{
	int res = 0, p = 0;
	for (int i = 30; i >= 0; i--)
	{
		int t = n >> i & 1;
		if (son[p][!t])
		{
			res += 1 << i;
			p = son[p][!t];
		}
		else
			p = son[p][t];
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		cin >> a[i];
		insert(a[i]);
	}
	int res = 0;
	for (int i = 0; i < n;i++)
	{
		res = max(res, query(a[i]));
	}
	cout << res;
	return 0;
}