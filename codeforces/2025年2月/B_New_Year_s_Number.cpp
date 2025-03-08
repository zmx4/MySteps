#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    ll n;cin>>n;
    while(n>=2020)
    {
        if(n%2020==0)
        {
            cout<<"YES"<<endl;
            return;
        }
        n-=2021;
    }
    if(n==0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
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