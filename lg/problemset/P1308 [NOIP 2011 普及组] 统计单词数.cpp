#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string target;
	getline(cin, target);
	string article;
	getline(cin, article);

	string tar;
	for (char c : target)
		tar.push_back(tolower(c));

	int cnt = 0;
	int pos = -1;
	int n = article.size();

	for (int i = 0; i < n;)
	{
		if (isspace(article[i]))
		{
			i++;
			continue;
		}
		int start = i;
		string token;
		while (i < n && !isspace(article[i]))
		{
			token.push_back(article[i]);
			i++;
		}
		string sstr;
		for (char c : token)
			sstr.push_back(tolower(c));
		if (sstr == tar)
		{
			cnt++;
			if (pos == -1)
				pos = start;
		}
	}

	if (cnt == 0)
		cout << -1;
	else
		cout << cnt << " " << pos;

	return 0;
}