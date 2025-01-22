#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	deque<int> dq;
	bool reversed_flag = false;

	while (m--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int a;
			cin >> a;
			if (!reversed_flag)
			{
				dq.push_front(a);
			}
			else
			{
				dq.push_back(a);
			}
		}
		else if (op == 2)
		{
			if (!reversed_flag)
			{
				dq.pop_front();
			}
			else
			{
				dq.pop_back();
			}
		}
		else if (op == 3)
		{
			int a;
			cin >> a;
			if (!reversed_flag)
			{
				dq.push_back(a);
			}
			else
			{
				dq.push_front(a);
			}
		}
		else if (op == 4)
		{
			if (!reversed_flag)
			{
				dq.pop_back();
			}
			else
			{
				dq.pop_front();
			}
		}
		else if (op == 5)
		{
			reversed_flag = !reversed_flag;
		}
		else if (op == 6)
		{
			cout << dq.size() << "\n";
			if (dq.empty())
			{
				cout << "\n";
				continue;
			}
			if (!reversed_flag)
			{
				for (auto it = dq.begin(); it != dq.end(); ++it)
				{
					if (it != dq.begin())
						cout << " ";
					cout << *it;
				}
				cout << "\n";
			}
			else
			{
				for (auto it = dq.rbegin(); it != dq.rend(); ++it)
				{
					if (it != dq.rbegin())
						cout << " ";
					cout << *it;
				}
				cout << "\n";
			}
		}
		else if (op == 7)
		{
			vector<int> tmp(dq.begin(), dq.end());
			if (reversed_flag)
			{
				reverse(tmp.begin(), tmp.end());
				reversed_flag = false;
			}
			sort(tmp.begin(), tmp.end());
			dq.clear();
			for (auto &x : tmp)
			{
				dq.push_back(x);
			}
		}
	}

	return 0;
}