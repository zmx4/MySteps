#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	list<int> l1, l2;
	int x;
	while (cin >> x)
	{
		if (x == -1)
			break;
		l1.push_back(x);
	}
	while (cin >> x)
	{
		if (x == -1)
			break;
		l2.push_back(x);
	}
	list<int> ans;
	while (!l1.empty() || !l2.empty())
	{
		if (l1.empty())
		{
			break;
		}
		if (l2.empty())
		{
			break;
		}
		if (l1.front() > l2.front())
		{
			l2.pop_front();
		}
		else if (l1.front() < l2.front())
		{
			l1.pop_front();
		}
		else
		{
			ans.push_back(l1.front());
			l2.pop_front();
			l1.pop_front();
		}
	}
	if (ans.empty())
	{
		cout << "NULL" << endl;
	}
	else
	{
		while (!ans.empty() && ans.size() != 1)
		{
			cout << ans.front() << " ";
			ans.pop_front();
		}
		cout << ans.front();
	}
	return 0;
}