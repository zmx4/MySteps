#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

// Function to convert a string to lowercase
string to_lower_str(string s)
{
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string line;
	getline(cin, line);
	istringstream iss(line);
	string word;
	map<string, int> word_count;
	while (iss >> word)
	{
		while (!word.empty() && !isalnum(word.back()))
		{
			word.pop_back();
		}
		while (!word.empty() && !isalnum(word.front()))
		{
			word.erase(0, 1);
		}
		if (!word.empty())
		{
			string lword = to_lower_str(word);
			word_count[lword]++;
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string Word;
		cin >> Word;
		string word1 = to_lower_str(Word);
		if (word_count.count(word1))
		{
			word_count[word1] = 0;
		}
	}

	int ans = 0;
	for (auto const &[_, val] : word_count)
	{
		if(val >= 1)ans ++;
	}

	cout << ans << endl;
	return 0;
}