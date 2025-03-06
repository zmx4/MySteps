#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, m;
	cin >> n>>m;
	list<int> l;
	vector<list<int>::iterator> pos(n + 1);
	for(int i = 1; i <= n; i++)
	{
		l.push_back(i);
		auto it = l.end();
		--it;
		pos[i] = it;
	}
	while(m--)
	{
		char op;int x;
		cin>>op>>x;
		if(op == 'L')
		{
			l.splice(l.begin(), l, pos[x]);
		}
		else if(op == 'R')
		{
			l.splice(l.end(), l, pos[x]);
		}
	}
	for(int x : l)
		cout<<x<<" ";
	return 0;
}