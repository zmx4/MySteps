#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    string s;cin>>s;
    while(!s.empty())
    {
        if(s[0]=='-'&&s[1]=='.')
        {
            cout<<1;
            s.erase(0,2);
        }
        else if(s[0]=='-'&&s[1]=='-')
        {
            cout<<2;
            s.erase(0,2);
        }
        else
        {
            cout<<0;
            s.erase(0,1);
        }
    }
	return 0;
}