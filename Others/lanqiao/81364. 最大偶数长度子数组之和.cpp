#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
#define int long long
const long long INF = 1e16;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif

    int n;
    cin >> n;
    if (n == 1)
    {
        cout << -2000000000;
        return 0;
    }
    // vector<int> a(n + 1);
    int minEven = 0, minOdd = INF;
    int ans = -INF;
    int prefixSum = 0;
    for (int i = 1; i <= n; i++)
    {
        int val;
        cin >> val;
        // prefixSum += a[i];
        prefixSum += val;
        if (i % 2 == 0)
        {
            ans = max(ans, prefixSum - minEven);
            minEven = min(minEven, prefixSum);
            // cout << ans << " ";
        }
        else
        {
            if (minOdd != INF)
            {
                ans = max(ans, prefixSum - minOdd);
            }
            minOdd = min(minOdd, prefixSum);
        }
        // cout << prefixSum << " ";
    }
    cout << ans << endl;

    return 0;
}