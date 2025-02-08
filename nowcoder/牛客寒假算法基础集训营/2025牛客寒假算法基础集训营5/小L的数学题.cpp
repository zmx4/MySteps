#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    ll n,m;cin>>n>>m;
    if(n==0 && m==0)
    {
        cout<<"Yes"<<endl;
        return;
    }
    else if(n==0 || m==0)
    {
        cout<<"No"<<endl;
        return;
    }
    else if(n == m)
    {
        cout<<"Yes"<<endl;
        return;
    }
    else
    {
        cout<<"Yes"<<endl;
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