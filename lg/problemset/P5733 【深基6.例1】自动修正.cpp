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
	for(auto &i : s)
	{
		i=toupper(i);
	}
	cout << s << endl;
	return 0;
}