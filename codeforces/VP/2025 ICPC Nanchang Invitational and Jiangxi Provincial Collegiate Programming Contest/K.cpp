#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(5);
    int x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x;
        a[x]++;
    }
    int ans = inf;
    for (int i = 0; i <= 3; ++i)
    {
        int sum = a[(i + 1) % 4] + a[(i + 2) % 4] * 2 + a[(i + 3) % 4] * 3;
        sum += (4 - (sum + i) % 4) % 4;
        // cout << sum << endl;
        ans = min(sum, ans);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}