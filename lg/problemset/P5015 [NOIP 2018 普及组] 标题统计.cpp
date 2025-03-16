#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;getline(cin, s);
	int cnt = 0;
	for(auto i : s)
	{
		if(isupper(i)||islower(i)||isdigit(i))
		{
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}