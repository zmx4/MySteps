#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool judge(ll n)
{
    ll a = sqrt(n);
    if(a*a == n)return true;
    return false;
}

void solve()
{
    int n;
    cin>>n;
    ll sum = 0;
    while(n--)
    {
        ll x;
        cin>>x;
        sum += x;
    }
    //cout<<sum<<endl;
    if(judge(sum))
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