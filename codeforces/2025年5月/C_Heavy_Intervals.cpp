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
    vector<int> l(n), r(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> l[i];
    for (int i = 0; i < n; i++)
        cin >> r[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int tt = 0;
    vector<int> diff(n);
    stack<int> s;
    for(int i = 0;i < n;i++)
    {
        while(l[tt]<r[i]&&tt < n)
        {
            s.push(l[tt]);
            tt++;
        }
        diff[i]=r[i]-s.top();
        s.pop();
    }
    sort(diff.begin(), diff.end(), greater<int>());
    sort(c.begin(), c.end());
    ll ans = 0;
    for(int i = 0;i < n;i++)
    {
        ans += (ll)diff[i] * c[i];
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // char readBuffer[1 << 20];
    // cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}