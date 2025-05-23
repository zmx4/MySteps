#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
const int MOD = 1e9+7;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll ans = 1;
    for(int i = 0;i < n;i++)
    {
        ll val = a[i] - i + 1;
        val %= MOD;
        ans = (ans * val) % MOD;
        if(val <= 0)
        {
            cout<<0<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;







    return 0;
}