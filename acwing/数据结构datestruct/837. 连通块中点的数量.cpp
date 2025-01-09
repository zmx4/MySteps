#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 1e5 + 10;
int n, m;
int p[N],ssize[N];

int find(int x)
{
	if(p[x]!=x)
		p[x] = find(p[x]);
	return p[x];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n;i++)
	{
		p[i] = i;
		ssize[i] = 1;
	}
	while (m--)
	{
		string op;
		cin >> op;
		int a, b;
		if (op == "C")
		{
			cin >> a >> b;
			if (find(a) == find(b))
				continue;
			ssize[find(b)] += ssize[find(a)];
			p[find(a)] = find(b);
		}
		else if (op == "Q1")
		{
			cin >> a >> b;
			if (find(a) == find(b))
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		else
		{
			cin >> a;
			cout << ssize[find(a)]<<endl;
		}
	}

	return 0;
}