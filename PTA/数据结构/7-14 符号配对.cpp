#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string str,s;
	while(getline(cin,s))
	{
		if(s == ".") break;
		str += s;
	}
	unordered_map<char,int> mp;
	int len = str.length();
	for(int i = 0; i < len; i++)
	{
		if(str[i] == '{'||str[i]=='['||str[i]=='(') mp[str[i]]++;
		if(str[i] == '}'||str[i]==']'||str[i]==')')
		{
			if(str[i] == '}') mp['{']--;
			if(str[i] == ']') mp['[']--;
			if(str[i] == ')') mp['(']--;
		}
		string tmp = str.substr(i,2);
		if(tmp == "/*")mp['/']++;
		if(tmp == "*/") mp['/']--;
	}
	for(auto i : mp)
	{
		if(i.second != 0)
		{
			cout << "NO" << endl;
			if(i.second>0 && i.first != '/')
				cout << i.first << "-?" << endl;
			else
				cout <<"?-"<< " " << i.first << endl;
			if (i.second > 0 && i.first == '/')
			{
				cout << "/*-*/" << endl;
			}
			else if (i.second < 0 && i.first == '/')
			{
				cout << "*/-/*" << endl;
			}
			return 0;
		}
	}



	return 0;
}