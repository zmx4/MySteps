#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    ll n, t, k;
    cin >> n >> t >> k;
    int ans1 = (n - k) / t, ans2 = k + 1;
    ll ans = min(ans1, ans2);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}