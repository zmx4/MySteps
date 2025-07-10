#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
vector<vector<int>> g;
vector<int> ind;
void solve()
{
    int n;
    cin >> n;
    g.assign(n + 1, vector<int>());
    ind.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        while (cin >> x)
        {
            if (x == 0)
                break;
            g[i].push_back(x);
            ind[x]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ind[j] == 0)
            {
                cout << j << " ";
                ind[j] = -1; // Mark as printed
                for (int k : g[j])
                {
                    ind[k]--;
                }
                break;
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // char readBuffer[1 << 20];
    // cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T = 1; // cin>>T;
    while (T--)
    {
        solve();
    }

    return 0;
}