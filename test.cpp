#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e16; // 设定一个足够大的无穷大值

int main()
{
    // 提升 I/O 效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n))
        return 0;

    int minEven = 0, minOdd = INF;
    int ans = -INF;
    int prefixSum = 0;

    for (int i = 1; i <= n; ++i)
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
            // 当前下标是奇数，减去之前的某个奇数下标前缀和
            if (minOdd != INF)
            {
                ans = max(ans, prefixSum - minOdd);
            }
            minOdd = min(minOdd, prefixSum);
        }
    }

    cout << ans << "\n";

    return 0;
}