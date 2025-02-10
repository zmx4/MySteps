//24-11-26 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;cin>>s;
	while (s.find("WUB") != string::npos)
	{
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='W'&&s[i+1]=='U'&&s[i+2]=='B')
			{
				s.erase(i,3);
				s.insert(i," ");
			}
		}
	}

	cout<<s;
    return 0;
}
