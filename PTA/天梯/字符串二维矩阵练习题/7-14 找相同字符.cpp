#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    string a, b;
    cin >> a >> b;
    int n1 = a.size(), n2 = b.size();
    ll ans = 0;
    vector<int> dp(n2 + 1, 0);
    for (int i = 1; i <= n1; ++i)
    {
        
        for (int j = n2; j >= 1; --j)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[j] = dp[j - 1] + 1;
                ans += dp[j];
            }
            else
            {
                dp[j] = 0;
            }
        }
    }
    cout << ans << endl;

    return 0;
}