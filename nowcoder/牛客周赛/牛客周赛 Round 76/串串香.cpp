#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 1e5 + 10;
char p[N];
int ne[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n;
	string s;

	cin >> n >> s;

	unordered_map<char, int> frequency;
	for (char c : s)
	{
		frequency[c]++;
	}

	char maxChar = s[0];
	int max_count = 0;
	for (const auto &pair : frequency)
	{
		if (pair.second > max_count)
		{
			max_count = pair.second;
			maxChar = pair.first;
		}
	}

	cout << maxChar << endl;

	return 0;
}