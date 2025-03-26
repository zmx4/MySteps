#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

ll upper(ll x, ll y)
{
    while(y--)
    {
        if(x == 0) return 0;
        x = ((x + 1) >> 1);
    }
    return x;
}

ll lowwer(ll x, ll y)
{
    while(y--)
    {
        if(x == 0) return 0;
        x = (x>>1);
    }
    return x;
}

void solve() {
    ll x, n, m;
    cin >> x >> n >> m;
    if(n == 0 && m == 0) {
        cout << x << " " << x << endl;
        return;
    }
    if(n == 0) {
        ll ans = upper(x, m);
        cout << ans << " " << ans << endl;
        return;
    }
    if(m == 0) {
        ll ans = lowwer(x, n);
        cout << ans << " " << ans << endl;
        return;
    }
    ll minn = lowwer( upper(x, n), m );
    ll maxx = upper( lowwer(x, m), n );
    cout << minn << " " << maxx << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}