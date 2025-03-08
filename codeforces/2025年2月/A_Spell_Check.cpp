#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;string s;
    cin>>n>>s;
    if(n!=5)
    {
        cout<<"NO"<<endl;
        return;
    }
    map<char,int> mp;
    for(int i = 0; i < n; i++)
    {
        if((s[i]=='i')||(s[i]=='m')||s[i]=='u'||s[i]=='r'||(s[i]=='T'))
        {
            mp[s[i]]++;
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    if((mp['i']==1)&&(mp['m']==1)&&(mp['u']==1)&&(mp['r']==1)&&(mp['T']==1))
    {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}