#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	deque<string> g;
	deque<string> b;
	vector<int> student(n);
	for (int i = 0; i < n; i++)
	{
		int x;
		string n;
		cin >> x >> n;
		cout << x << n << endl;
		student[i] = x;
		if (x == 0)
			g.push_back(n);
		else
			b.push_back(n);
	}

	for (int i = 0; i < (n / 2) - 1; i++)
	{
		if (student[i] == 1)
		{
			string x = b.front(), y = g.back();
			cout << x << " " << y << endl;
			b.pop_front();
			g.pop_back();
		}
		else
		{
			string x = g.front(), y = b.back();
			cout << x << " " << y << endl;
			g.pop_front();
			b.pop_back();
		}
	}

	return 0;
}