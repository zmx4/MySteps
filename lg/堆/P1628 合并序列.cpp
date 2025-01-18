#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<string> words(n);
	for (auto &word : words)
		cin >> word;

	string T;
	cin >> T;
	int len = T.size();
	vector<string> result;
	for (auto &word : words)
	{
		if (word.substr(0, len) == T)
		{
			result.push_back(word);
		}
	}
	sort(result.begin(), result.end());

	for (auto &word : result)
	{
		cout << word << '\n';
	}

	return 0;
}