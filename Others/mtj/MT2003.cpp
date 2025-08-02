#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
// bool check(int n)
// {
//     if (n * (n + 1) / 2 > n)
//         return false; // 检查是否满足条件
//     return true;      // 满足条件
// }
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a;
    // for (int i = 0;; i++)
    // {
    //     int x = i * (i + 1) / 2;
    //     if(x > n    ) break;
    //     a.push_back(x);
    // }
    // for (int i = 0; i < (n + 1) / 2; i++)
    // {
    //     if (binary_search(a.begin(), a.end(), n - a[i]))
    //     {
    //         cout << "YES" << endl;
    //         return 0;
    //     }
    // }
    // cout << "NO" << endl;
    for (int i = 1; i * (i + 1) / 2 <= n; i++)
    {
        int x = i * (i + 1) / 2;
        int y = n - x;
        int l = 1, r = i;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (mid * (mid + 1) / 2 == y)
            {
                cout << "YES" << endl;
                return 0;
            }
            else if (mid * (mid + 1) / 2 < y)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        
    }
    cout << "NO" << endl;
    return 0;
}