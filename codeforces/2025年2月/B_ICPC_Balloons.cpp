#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    bool st[26] = {false};
    int n;cin>>n;
    string s;cin>>s;
    int ans = 0;
    for(int i=0;i<n;++i)
    {
        if(st[s[i]-'A'])
        {
            ans++;
        }
        else
        {
            ans+=2;
            st[s[i]-'A']=true;
        }
    }
    cout<<ans<<endl;
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