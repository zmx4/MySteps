#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;

		if (n == 2)
		{
			if (s[0] == s[1])
			{
				cout << "0"<<endl;
			}
			else
			{
				cout << "-1"<<endl;
			}
			continue;
		}

		vector<vector<int>> pos(26, vector<int>());
		for (int i = 0; i < n; i++)
		{
			pos[s[i] - 'a'].push_back(i);
		}

		int minNum = INT_MAX;
		bool possible = false;

		for (int i = 0; i < 26; i++)
		{
			if (pos[i].size() >= 2)
			{
				for (int j = 1; j < pos[i].size(); j++)
				{
					int distance = pos[i][j] - pos[i][j - 1] - 1;
					minNum = min(minNum, distance);
					if (distance == 0)
					{
						possible = true;
						break;
					}
				}
				if (pos[i].size() >= 2)
				{
					int distance = (n - pos[i].back() + pos[i][0] - 1);
					minNum = min(minNum, distance);
					if (distance == 0)
					{
						possible = true;
					}
				}
			}
		}

		bool broken = false;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == s[(i + 1) % n])
			{
				broken = true;
				break;
			}
		}

		if (broken)
		{
			cout << "0"<<endl;
		}
		else if (minNum != INT_MAX)
		{
			if (n - (minNum + 1) == 2)
			{
				cout << minNum << endl;
			}
			else
			{
				cout << minNum << endl;
			}
		}
		else
		{
			cout << "-1"<<endl;
		}
	}

	return 0;
}