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
	for (int i = 0; i < s.length();i++)
		if(s[i]<='Z'&&s[i]>='A')s[i] = tolower(s[i]);
	auto pos = s.find("bob");
	if (pos != string::npos)
	{
		cout << pos << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}
