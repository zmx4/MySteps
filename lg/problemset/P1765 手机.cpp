#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	map<char, int> mp;
	mp['a'] = 1, mp['d']=1, mp['g']=1, mp['j']=1, mp['m']=1, mp['p']=1, mp['t']=1, mp['w']=1;
	mp['b'] = 2, mp['e']=2, mp['h']=2, mp['k']=2, mp['n']=2, mp['q']=2, mp['u']=2, mp['x']=2;
	mp['c'] = 3, mp['f']=3, mp['i']=3, mp['l']=3, mp['o']=3, mp['r']=3, mp['v']=3, mp['y']=3;
	mp['z'] = 4, mp['s'] = 4;
	string s;
	getline(cin, s);
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ') ans+=1;
		if (mp[s[i]] == 1) ans += 1;
		else if (mp[s[i]] == 2) ans += 2;
		else if (mp[s[i]] == 3) ans += 3;
		else if (mp[s[i]] == 4) ans += 4;
	}
	cout << ans << endl;






	return 0;
}