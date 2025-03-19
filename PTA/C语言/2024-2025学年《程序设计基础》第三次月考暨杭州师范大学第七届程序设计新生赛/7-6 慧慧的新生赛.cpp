#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct team
{
	string name;
	int solved;
	int time;
};

bool compare(const team &a, const team &b)
{
	if (a.solved != b.solved)
		return a.solved > b.solved;
	else if (a.time != b.time)
		return a.time < b.time;
	else
		return a.name < b.name;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<team> teams(n);
	for (int i = 0; i < n; i++)
	{
		cin >> teams[i].name;
		teams[i].solved = 0;
		for (int j = 0; j < 6; j++)
		{
			char c;
			cin >> c;
			if (c == '+')
				teams[i].solved++;
		}
		cin >> teams[i].time;
	}

	sort(teams.begin(), teams.end(), compare);

	for (int i = 0; i < k; i++)
		cout << teams[i].name << endl;
}