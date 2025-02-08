#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	list<int> Q;
	vector<list<int>::iterator> pos(n + 1);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		Q.push_back(x);
		auto it = Q.end();
		--it;
		pos[x] = it;
	}

	int p;
	cin >> p;
	while (p--)
	{
		string op;
		int x;
		cin >> op >> x;
		auto it = pos[x];
		if (op == "FIRST")
		{
			Q.splice(Q.begin(), Q, it);
		}
		else if (op == "LAST")
		{
			Q.splice(Q.end(), Q, it);
		}
	}

	for (int x : Q)
		cout << x << " ";
	cout << endl;

	return 0;
}