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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ranges::sort(a);
    int idx = 0;
    for (int k = 0; k <= n; k++)
    {
        while (idx < n && a[idx] <= k)
        {
            idx++;
        }
        int truthful = idx;
        int liars = n - truthful;
        if (liars == k)
        {
            cout << k << endl;
            return;
        }
    }
    cout << -1 << endl;
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