#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
ll qpow(ll x, ll p)
{
    ll res = 1;
    for (; p; p >>= 1, x = x * x)
        if (p & 1)
            res = res * x;
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ll n;
    cin >> n;
    ll t = 1;
    ll ans = -1;
    ll tar = -1;
    for (int k = 1; k <= 10;k++)
    {
        t = 1;
        for (int i = 2; i <= n;i++)
        {
            t += qpow(i, k);
            if(t > n)
            {
                break;
            }
            if(t == n)
            {
                ans = k;
                tar = i;
            }
        }
    }
    t = 1;
    if(ans == -1)
    {
        cout << "Impossible for " << n << "." << endl;
        return 0;
    }
    for (int i = 1;i <= tar;i++)
    {
        cout << i << "^" << ans << (i == tar ? "" : "+");
    }

        return 0;
}