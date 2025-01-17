#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll fact(ll n)
{
	if (n == 1)
		return 1;
	return n * fact(n - 1);
}

ll modExp(ll base, ll exp, ll mod)
{
	if (exp == 0)
		return 1;
	ll result = 1;
	base = base % mod;
	while (exp > 0)
	{
		if (exp % 2 == 1)
		{
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exp = exp / 2;
	}
	return result;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		int pos, prepos, afpos;
		// 计算阶乘
		pos = s.find('!'), prepos = pos - 1;

		while (s.find('!') != string::npos)
		{
			// cout<<pos<<" "<<prepos<<endl;
			while (prepos > 0 && isdigit(s[prepos - 1]))
				prepos--;
			// cout << pos << " " << prepos << endl;
			ll n = stoll(s.substr(prepos, pos - prepos + 1));
			ll res = fact(n);
			res %= 65536;
			s.erase(prepos, pos - prepos + 1);
			// cout << s << endl;
			s.insert(prepos, to_string(res));
			// cout << s << endl;
			auto pos = s.find('!');
			int prepos = pos - 1;
		}
		cout << s << endl;
		// 计算幂
		pos = s.find('^'), prepos = pos - 1, afpos = pos + 1;
		while (s.find('^') != string::npos)
		{
			while (prepos > 0 && isdigit(s[prepos - 1]))
				prepos--;
			while (afpos < s.size() && isdigit(s[afpos + 1]))
				afpos++;
			ll base = stoll(s.substr(prepos, pos - prepos));
			ll exp = stoll(s.substr(pos + 1, afpos - pos));
			ll res = modExp(base, exp, 65536);
			res %= 65536;
			s.erase(prepos, afpos - prepos + 1);
			s.insert(prepos, to_string(res));
			auto pos = s.find('^');
			int prepos = pos - 1;
			int afpos = pos + 1;
		}
		cout << s << endl;
		// 计算乘法
		pos = s.find('*'), prepos = pos - 1, afpos = pos + 1;
		while (s.find('*') != string::npos)
		{
			while (prepos > 0 && isdigit(s[prepos - 1]))
				prepos--;
			while (afpos < s.size() && isdigit(s[afpos + 1]))
				afpos++;
			ll base = stoll(s.substr(prepos, pos - prepos));
			ll exp = stoll(s.substr(pos + 1, afpos - pos));
			ll res = base * exp;
			res %= 65536;
			s.erase(prepos, afpos - prepos + 1);
			s.insert(prepos, to_string(res));
			auto pos = s.find('*');
			int prepos = pos - 1;
			int afpos = pos + 1;
		}
		cout << s << endl;
	}

	return 0;
}