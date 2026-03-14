#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();
	map<string, vector<string>> mp;
	string str;
	while(n--)
	{
		getline(cin, str);
		istringstream st(str);
		string temp, f = "";
		while(st>>temp)
		{
			if(!temp.empty())f += toupper(temp[0]);
		}
		mp[f].push_back(str);
	}
	for (auto &[abbr, sentences] : mp)
	{
		sort(sentences.begin(), sentences.end());
	}
	int m;
	cin >> m;
	cin.ignore();
	while (m--)
	{
		getline(cin, str);
		istringstream ss(str);
		string word, abbr = "";
		while (ss >> word)
		{
			if (!word.empty())
				abbr += toupper(word[0]);
		}
		if (mp.find(abbr) != mp.end())
		{
			for (auto i = 0; i < mp[abbr].size(); ++i)
			{
				cout << mp[abbr][i];
				if (i < mp[abbr].size() - 1)
					cout << "|";
			}
			cout << endl;
		}
		else
		{
			cout << str << endl;
		}
	}

	return 0;
}