#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n;cin>>n;
    string s;
    cin >> s;
    ll curspeed=0,curlen=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            curspeed += 10;
            curlen += curspeed;
        }
        else if (s[i] == '1')
        {
            if (curspeed >= 5)
                curspeed -= 5;
            else
                curspeed = 0;
            curlen += curspeed;
        }
        else if(s[i]=='2')
        {
            ll tempspeed = curspeed;
            if(tempspeed>=10) tempspeed-=10;
            else tempspeed=0;
            curlen=curlen+tempspeed;
        }
    }
    cout<<curlen<<endl;
	return 0;
}