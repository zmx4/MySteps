#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+5;
int a[N],n,m;
int find(int x)
{
	if(a[x]!=x)
	{
		a[x] = find(a[x]);
	}
	return a[x];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		a[i] = i;
	while(m--)
	{
		char op;
		int x, y;
		cin >> op >> x >> y;
		if(op == 'M')
			a[find(x)] = find(y);
		else
		{
			if(find(x) == find(y))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}








	return 0;
}