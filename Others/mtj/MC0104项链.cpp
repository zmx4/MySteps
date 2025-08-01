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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    vector<int>b(n + 1);
    int l = 1, r = n;
    for(int i = 1; i <= n; i++)
    {
        if(i & 1) b[i] = a[l++];
        else b[i] = a[r--];
    }
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        ans += abs(b[i] - b[i + 1]);
    }
    ans+= abs(b[n] - b[1]); // 连接首尾
    cout << ans << endl;
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
    //cin >> T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}