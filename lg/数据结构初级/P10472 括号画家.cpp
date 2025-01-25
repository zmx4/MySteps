#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
int stk[10000];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;
	cin >> s;
	s = " " + s;
	int ans = 0,maxn = 0;
	for(int i = 0; i < s.size(); i++)
	{
		int tt = 0;
		for (int j = i; j < s.size();j++)
		{
			if((s[stk[tt]]=='['&&s[j]==']')||(s[stk[tt]]=='{'&&s[j]=='}')||(s[stk[tt]]=='('&&s[j]==')'))
				tt--;
			else if (s[j] == ']' || s[j] == '}' || s[j] == ')')
				break;
			else
				stk[++tt] = j;
			if(tt == 0)
				ans = max(ans, j - i + 1);
		}
	}
	cout << ans << endl;
	return 0;
}