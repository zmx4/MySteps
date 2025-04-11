#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);




	vector<string> s(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> s[i];
	}
	int ans = 0;
	for(int i = 0; i < 5; i++)
	{
		if (s[i][0] == s[i][2] && stoi(to_string(s[i][1])) + 1 == stoi(to_string(s[i][3])))
			ans++;
	}
	cout << ans << endl;




	return 0;
}