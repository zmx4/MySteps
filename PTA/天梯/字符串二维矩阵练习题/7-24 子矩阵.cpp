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

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    vector<vector<int>> sum(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + g[i][j];
        }
    }
    while(q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << endl;
    }








    return 0;
}