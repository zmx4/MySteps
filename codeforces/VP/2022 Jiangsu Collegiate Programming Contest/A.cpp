#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	unordered_map<string, vector<string>> mp;
	for (int i = 0; i < n; i++)
	{
		string k, d;
		cin >> k >> d;
		mp[k].push_back(d);
	}
	for (auto &p : mp)
	{
		const vector<string> &ds = p.second;
		unordered_map<string, int> freq;
		int i = 0;
		for (int j = 0; j < (int)ds.size(); j++)
		{
			freq[ds[j]]++;
			/*
			121345
			122345
			211345
			122345
			132254
			123345
			*/
			while (freq[ds[j]] > 1)
			{
				freq[ds[i]]--;
				i++;
			}
			if (j - i + 1 >= 5)
			{
				cout << "PENTA KILL!" << endl;
				return 0;
			}
		}
	}
	cout << "SAD:("<<endl;
	return 0;
}