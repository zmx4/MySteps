#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	for(auto &i : s)
	{
		i = (i - 'a' + n) % 26 + 'a';
	}
	cout << s << endl;

	return 0;
}