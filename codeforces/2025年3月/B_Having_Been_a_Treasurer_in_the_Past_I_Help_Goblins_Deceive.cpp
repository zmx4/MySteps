#include <bits/stdc++.h>
#define endl "\n"
#define ll int64_t
using namespace std;

void solve()
{
    int n;cin>>n;
    string s;cin>>s;
    map<char,ll> mp;
    for(int i = 0;i < n;i++)mp[s[i]]++;
    cout<<(mp['-']/2)*(mp['-']-mp['-']/2)*mp['_']<<endl;
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