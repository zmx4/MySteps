#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> b(n + 1), g(n + 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     if (a[i] == 0)
    //     {
    //         g[i] = g[i - 1] + 1;
    //         b[i] = b[i - 1];
    //     }
    //     else
    //     {
    //         b[i] = b[i - 1] + 1;
    //         g[i] = g[i - 1];
    //     }
    // }
    // int ans = 0;
    // for (int i = n; i >= 1; i--)
    // {
    //     if (b[i] == g[i])
    //         ans = max(ans, i);
    //     else if (b[i] > g[i])
    //     {
    //         int dif = b[i] - g[i];
    //         auto it = lower_bound(b.begin(), b.end(), dif);
    //         ans = max(ans, (int)(i-(it - b.begin())));
    //     }
    //     else
    //     {
    //         int dif = g[i] - b[i];
    //         auto it = lower_bound(g.begin(), g.end(), dif);
    //         ans = max(ans, (int)(i - (it - g.begin())));
    //     }
    // }
    // cout << ans << endl;
    unordered_map<int, int> mp;
    mp[0] = 0; // Initialize with the base case
    int diff = 0,ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
            diff++;
        else
            diff--;
        if(mp.count(diff))
        {
            ans = max(ans, i - mp[diff]);
        }else{
            mp[diff] = i;
        }
    }
    cout << ans << endl;
    return 0;
}