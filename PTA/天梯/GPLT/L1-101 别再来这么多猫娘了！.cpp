#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<string> ban;
	ban.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> ban[i];
	}
	int k;
	cin >> k;
	cin.ignore();
	string s;
	getline(cin, s);

	string res;		 
	int countBan = 0; 
	int i = 0;
	int len = s.size();
	while (i < len)
	{
		bool found = false;
		for (int j = 0; j < n; j++)
		{
			string word = ban[j];
			int wlen = word.size();
			if (i + wlen <= len && s.substr(i, wlen) == word)
			{
				res += "<censored>";
				countBan++;
				i += wlen;
				found = true;
				break;
			}
		}
		if (!found)
		{
			res.push_back(s[i]);
			i++;
		}
	}
	
	if (countBan < k)
	{
		cout << res;
	}
	else
	{
		cout << countBan << "\n"
			 << "He Xie Ni Quan Jia!";
	}
	return 0;
}