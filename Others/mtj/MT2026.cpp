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

    int n, m;
    cin >> n >> m;
    vector<int> flat_a(n * m);
    for (int i = 0; i < n * m; ++i)
    {
        cin >> flat_a[i];
    }

    int k;
    cin >> k;

    int total_elements = n * m;
    int effective_k = k % total_elements;

    vector<vector<int>> result(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int dest_p = i * m + j;
            int src_p = (dest_p - effective_k + total_elements) % total_elements;
            result[i][j] = flat_a[src_p];
        }
    }

    // 5. 输出结果
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << result[i][j] << (j == m - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}