#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
bool is_prime(int x)
{
	if(x < 2)
		return false;
	for(int i = 2; i * i <= x; i++)
	{
		if(x % i == 0)
			return false;
	}
	return true;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;
	cin >> s;
	map<char, int> mp;
	for(auto i : s)
	{
		mp[i]++;
	}
	int maxn = 0, minn = 0x3f3f3f3f;
	for(auto i : mp)
	{
		maxn = max(maxn, i.second);
		minn = min(minn, i.second);
	}
	if(is_prime(maxn - minn))
		cout << "Lucky Word" << endl << maxn - minn << endl;
	else
		cout << "No Answer" << endl
			 << 0 << endl;

	return 0;
}