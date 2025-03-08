#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const string str = "codeforces";

void solve()
{
    string s;
    cin>>s;
    int ans = 0;
    for(int i=0;i<str.size();i++)
    {
        if(s[i]!=str[i])
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return;
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