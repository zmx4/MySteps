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
	set<int> s;
	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < n; i++)
	{
		string op;
		cin >> op;
		if (op == "New")
		{
			int id;
			if (q.empty())
			{
				id = s.size() + 1;
			}
			else
			{
				id = q.top();
				q.pop();
			}
			s.insert(id);
			cout << id << endl;
		}
		else if (op == "Delete")
		{
			int x;
			cin >> x;
			if (s.find(x) != s.end())
			{
				s.erase(x);
				q.push(x);
				cout << "Successful" << endl;
			}
			else
			{
				cout << "Failed" << endl;
			}
		}
	}
	return 0;
}