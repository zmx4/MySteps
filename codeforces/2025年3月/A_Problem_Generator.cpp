#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    map<int,int> mp;
    for(int i = 0;i < s.size();i++)
    {
        mp[s[i]-'A']++;
    }
    int ans = 0;
    for(int i = 0;i <= 6;i++)
    {
        int cnt =m - mp[i];
        if(cnt>=0)
        {
            ans+=cnt;
            // cout<<char('A'+i)<<" "<<cnt<<endl;
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