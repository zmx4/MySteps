#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    ll n;
    cin>>n;
    vector<pair<ll,ll>> a(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end());
    for(ll i = 0;i <n-1;i++)
    {
        if(a[i].first==a[i+1].first)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}