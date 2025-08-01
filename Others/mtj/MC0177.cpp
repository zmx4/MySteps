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
    int n,a,b;
    cin>> n >> a >> b;
    bool ok = true;
    int k = n / 2;
    if (a <= b)
    {
        // 前半段最小值为 a，需 a <= k 且 b 在后半段有位置，即 b >= k+1
        ok = (a <= k && b >= k + 1);
    }
    else
    {
        // a > b，此时 a 在大半区，需 b 在前半段末尾有位置，即 b >= k
        // 且 a 在前半段大小不超过 k+1
        ok = (a <= k + 1 && b >= k);
    }
    cout << (ok ? "YES" : "NO") << "\n";
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