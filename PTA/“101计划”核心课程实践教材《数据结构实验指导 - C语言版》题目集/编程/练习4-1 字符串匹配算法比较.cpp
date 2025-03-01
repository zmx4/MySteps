#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s1;
	getline(cin, s1);
	s1 = ' ' + s1;
	int n = s1.size();
	int T;
	cin >> T;
	vector<int> ne(n + 1);
	while(T--)
	{	
		string s2;
		cin >> s2;
		s2 = ' ' + s2;
		int m = s2.size();
		for (int i = 2, j = 0; i < m; i++)
		{
			while (j && s2[i] != s2[j + 1])
				j = ne[j];
			if (s2[i] == s2[j + 1])
				j++;
			ne[i] = j;
		}

		int pos = 0;
		bool found = false;
		for (int i = 1, j = 0; i < n; i++)
		{
			while (j && s1[i] != s2[j + 1])
				j = ne[j];
			if (s1[i] == s2[j + 1])
				j++;
			if (j == m - 1)
			{
				pos = i - m + 1;
				found = true;
				break;
			}
		}

		if (found)
			cout << s1.substr(pos+1) << endl;
		else
			cout << "Not Found" << endl;
	}

	return 0;
}