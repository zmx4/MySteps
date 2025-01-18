#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	priority_queue<int,vector<int>,greater<int>> q;
	while (n--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (op == 2)
		{
			cout << q.top() << endl;
		}
		else
		{
			q.pop();
		}
	}

	return 0;
}