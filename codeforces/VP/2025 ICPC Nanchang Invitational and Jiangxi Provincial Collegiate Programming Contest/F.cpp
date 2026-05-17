#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

void solve()
{
    int n, k;
    double L, R, p;
    double c[N], r[N];
    cin >> n >> k;
    cin >> r[0] >> c[0] >> p >> L >> R;
    for (int i = 1; i <= n;++i)
    {
        r[i] = L;
    }
    for (int i = 1; i <= k;++i)
    {
        int a;
        double b;
        cin >> a >> b;
        r[a] = b;
    }
    double ans = 0;
    for (int i = 1; i <= n;++i)
    {
        c[i] = p * c[i - 1] + (1 - p) * r[i - 1];
        ans += c[i] - r[i];
    }
    cout << format("{:.10f}",ans) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    #if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    #endif
    int T = 1;
    cin >> T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}