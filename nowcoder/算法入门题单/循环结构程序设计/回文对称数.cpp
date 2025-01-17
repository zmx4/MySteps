#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool isHuiwen(string s)
{
	if(s.size() == 1)
		return true;
	int len = s.size();
	for(int i = 0; i < len / 2; i++)
	{
		if(s[i] != s[len - i - 1])
			return false;
	}
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		if(isHuiwen(to_string(i)))
			cout << i << endl;
	}
		return 0;
}