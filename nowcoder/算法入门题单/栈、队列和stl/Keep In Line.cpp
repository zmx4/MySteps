#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	int n;
	cin >> n;

	queue<string> line;
	unordered_map<string, bool> st;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		string op, name;
		cin >> op >> name;

		if (op == "in")
		{
			line.push(name);
		}
		else if (op == "out")
		{
			while (!line.empty() && st[line.front()])
				line.pop();
			if(name!=line.front())
			{
				st[name] = true;
			}
			else
			{
				cnt++;
				line.pop();
			}
			
		}
	}

	cout << cnt << endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin >> T;
	while(T--)
	{
		solve();
	}

	return 0;
}