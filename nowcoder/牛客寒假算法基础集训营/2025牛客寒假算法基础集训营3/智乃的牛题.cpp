#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;
	cin >> s;
	unordered_map<char, int> cnt;
	for (auto c : s)
	{
		cnt[c]++;
	}
	if (cnt['n'] == 1 && cnt['o'] == 2 &&
		cnt['w'] == 1 && cnt['c'] == 1 &&
		cnt['d'] == 1 && cnt['e'] == 1 &&
		cnt['r'] == 1)
		cout << "happy new year" << endl;
	else
		cout << "I AK IOI" << endl;

			return 0;
}