#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const string str = "while";
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int cnt = 0;
	string s;
	cin >> s;
	for (int i = 0; i < str.size(); i++)
	{
		if(s[i]!=str[i])
		{
			cnt++;
		}
	}
	cout << cnt << endl;
		return 0;
}