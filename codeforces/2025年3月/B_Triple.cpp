#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;cin>>n;
    int x;
    map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        cin>>x;
        mp[x]++;
    }
    for(auto i:mp)
    {
        if(i.second >= 3)
        {
            cout<<i.first<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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