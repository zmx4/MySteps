#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 100010;

int p[N];
int n, m;

int find(int x)
{
	if(p[x]!=x)
	{
		p[x] = find(p[x]);
	}
	return p[x];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1;i <= n;i++ )
		p[i] = i;
	while(m--)
	{
		char op;
		int a, b;
		cin >> op >> a >> b;
		if(op=='M')
			p[find(a)] = find(b);
		else
		{
			if (find(a) == find(b))
			{
				cout << "Yes" << endl;
			}
			else
				cout << "No" << endl;
		}
	}
	return 0;
}