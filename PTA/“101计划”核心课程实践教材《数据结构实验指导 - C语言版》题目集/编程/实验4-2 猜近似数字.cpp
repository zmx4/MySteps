#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;
	cin>>s;
	string str;
	while(cin>>str)
	{
		if(str=="-1")break;
		if(abs((int)str.size()-(int)s.size())>1)
		{
			cout<<"NO"<<endl;
			continue;
		}
		if(s[0]!=str[0])
		{
			for(int i = 1; i < s.size(); i++)
			{
				if (s[i] != str[i - 1] && (abs((int)s[i] - (int)str[i - 1]) > 1))
				{
					cout<<"NO"<<endl;
					break;
				}
				if(i==s.size()-1)
				{
					cout<<"YES"<<endl;
				}
			}
		}
		else
		{
			for(int i = 1; i < s.size(); i++)
			{
				if(s[i]!=str[i]&&(abs((int)s[i]-(int)str[i])>1))
				{
					cout<<"NO"<<endl;
					break;
				}
				if(i==s.size()-1)
				{
					cout<<"YES"<<endl;
				}
			}
		}
	}

	return 0;
}