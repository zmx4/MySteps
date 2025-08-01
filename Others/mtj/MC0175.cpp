#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
bool vis[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<char> vis(n + 1, 0); // 0=unvisited,1=visiting,2=done
    vector<char> ans(n + 1, 0); // 1 = Y, 0 = N

    function<bool(int)> dfs = [&](int u) -> bool
    {
        if (vis[u] == 2)
        {
            return ans[u];
        }
        if (vis[u] == 1)
        {
            // found a cycle; mark all nodes in this cycle
            int v = u;
            do
            {
                ans[v] = 1;
                v = v + a[v];
            } while (v != u);
            return true;
        }
        vis[u] = 1;
        bool res = false;
        if (a[u] == 0)
        {
            // terminal (defective portal)
            res = false;
        }
        else
        {
            int v = u + a[u];
            res = dfs(v);
            if (res)
                ans[u] = 1;
        }
        vis[u] = 2;
        return ans[u];
    };

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }

    // output
    for (int i = 1; i <= n; i++)
    {
        cout << (ans[i] ? 'Y' : 'N');
    }
    cout << endl;

    return 0;
}