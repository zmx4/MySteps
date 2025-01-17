#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll fact(ll n)
{
	if(n==1)
		return 1;
	return n*fact(n-1);
}

ll modExp(ll base, ll exp, ll mod)
{
	if(exp==0)
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
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		//计算阶乘
		int pos = s.find('!');
		int prepos = pos - 1;

		while (s.find('!') != string::npos)
		{
			//cout<<pos<<" "<<prepos<<endl;
			while(prepos>0&&isdigit(s[prepos]))
				prepos--;
			ll n = stoll(s.substr(prepos,pos-prepos));
			ll res = fact(n);
			res %= 65536;
			s.erase(prepos,pos-prepos+1);
			//cout << s << endl;
			s.insert(prepos,to_string(res));
			cout << s << endl;
			auto pos = s.find('!');
			int prepos = pos - 1;
		}
		//幂运算
		pos = s.find('^');
		prepos = pos - 1;
		int afpos = pos + 1;
		while (s.find('^') != string::npos)
		{
			while(prepos>0&&isdigit(s[prepos]))
				prepos--;
			while(afpos<s.size()&&isdigit(s[afpos]))
				afpos++;
			ll n = stoll(s.substr(prepos,pos-prepos));
			ll m = stoll(s.substr(pos+1,afpos-pos-1));
			ll res = modExp(n,m,65536);
			res %= 65536;
			s.erase(prepos,afpos-prepos);
			s.insert(prepos,to_string(res));
			cout << s << endl;
			auto pos = s.find('^');
			int prepos = pos - 1;
			int afpos = pos + 1;
		}
		//乘除
		pos = s.find('*');
		prepos = pos - 1;
		afpos = pos + 1;
		while (s.find('*') != string::npos)
		{
			while(prepos>0&&isdigit(s[prepos]))
				prepos--;
			while(afpos<s.size()&&isdigit(s[afpos]))
				afpos++;
			ll n = stoll(s.substr(prepos,pos-prepos));
			ll m = stoll(s.substr(pos+1,afpos-pos-1));
			ll res = n*m;
			res %= 65536;
			s.erase(prepos,afpos-prepos);
			s.insert(prepos,to_string(res));
			cout << s << endl;
			auto pos = s.find('*');
			int prepos = pos - 1;
			int afpos = pos + 1;
		}
		pos = s.find('/');
		prepos = pos - 1;
		afpos = pos + 1;
		while (s.find('/') != string::npos)
		{
			while(prepos>0&&isdigit(s[prepos]))
				prepos--;
			while(afpos<s.size()&&isdigit(s[afpos]))
				afpos++;
			ll n = stoll(s.substr(prepos,pos-prepos));
			ll m = stoll(s.substr(pos+1,afpos-pos-1));
			if(m==0)
			{
				cout << "ArithmeticException" << endl;
				continue;
			}
			ll res = n/m;
			res %= 65536;
			s.erase(prepos,afpos-prepos);
			s.insert(prepos,to_string(res));
			cout << s << endl;
			auto pos = s.find('/');
			int prepos = pos - 1;
			int afpos = pos + 1;
		}
		//加减
		pos = s.find('+');
		prepos = pos - 1;
		afpos = pos + 1;
		while (s.find('+') != string::npos)
		{
			while(prepos>0&&isdigit(s[prepos]))
				prepos--;
			while(afpos<s.size()&&isdigit(s[afpos]))
				afpos++;
			ll n = stoll(s.substr(prepos,pos-prepos));
			ll m = stoll(s.substr(pos+1,afpos-pos-1));
			ll res = n+m;
			res %= 65536;
			s.erase(prepos,afpos-prepos);
			s.insert(prepos,to_string(res));
			cout << s << endl;
			auto pos = s.find('+');
			int prepos = pos - 1;
			int afpos = pos + 1;
		}
		pos = s.find('-');
		prepos = pos - 1;
		afpos = pos + 1;
		while (s.find('-') != string::npos)
		{
			while(prepos>0&&isdigit(s[prepos]))
				prepos--;
			while(afpos<s.size()&&isdigit(s[afpos]))
				afpos++;
			ll n = stoll(s.substr(prepos,pos-prepos));
			ll m = stoll(s.substr(pos+1,afpos-pos-1));
			ll res = n-m;
			res %= 65536;
			s.erase(prepos,afpos-prepos);
			s.insert(prepos,to_string(res));
			cout << s << endl;
			auto pos = s.find('-');
			int prepos = pos - 1;
			int afpos = pos + 1;
		}
		cout << s << endl;
	}

	return 0;
}