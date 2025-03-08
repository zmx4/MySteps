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
    for(int i = 1;i < s.size();i++)
    {
        if(s[i]-'0'>4)s[i] = '9' - s[i] + '0';
    }
    if(s[0]!='9'&&s[0]-'0'>4)s[0] = '9' - s[0] + '0';
    cout<<s<<endl;
	return 0;
}