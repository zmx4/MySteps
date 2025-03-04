#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n,k;cin>>n>>k;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        mp[x]++;
    }
    if(mp[k]==0)
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        cout<<"YES"<<endl;
        return;
    }
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