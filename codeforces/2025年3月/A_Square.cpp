#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    pair<int,int> a,b,c,d;
    cin>>a.first>>a.second;
    cin>>b.first>>b.second;
    cin>>c.first>>c.second;
    cin>>d.first>>d.second;
    if(a.first==b.first)
    {
        cout<<abs(a.second-b.second)*abs(a.second-b.second)<<endl;
    }
    else if(a.first==c.first)
    {
        cout<<abs(a.second-c.second)*abs(a.second-c.second)<<endl;
    }
    else if(a.first==d.first)
    {
        cout<<abs(a.second-d.second)*abs(a.second-d.second)<<endl;
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