#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const ll maxn = 1e10+5;

void solve()
{
    int n,k;
    cin>>n>>k;
    /*
    int ans = k/(n-1)*n+k%(n-1);
    if(ans%n==0) ans--;
    cout<<ans<<endl;
    */
    ll r = maxn, l = 1;
    while(l<r)
    {
        ll mid = (l+r)/2;
        ll cnt = mid-mid/n;
        if(cnt>=k) r = mid;
        else l = mid+1;
    }
    cout<<l<<endl;
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