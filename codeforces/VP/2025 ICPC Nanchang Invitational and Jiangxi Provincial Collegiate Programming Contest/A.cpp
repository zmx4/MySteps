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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (a + b + c) * d;
}

signed main()a
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    #if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    #endif
    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}