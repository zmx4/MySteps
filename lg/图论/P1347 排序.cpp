#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> indeg(n, 0);
    vector<vector<bool>> edge(n, vector<bool>(n, false));

    for (int i = 1; i <= m; i++)
    {
        char A, lt, B;
        cin >> A >> lt >> B;
        int u = A - 'A', v = B - 'A';
        if (!edge[u][v])
        {
            g[u].push_back(v);
            indeg[v]++;
            edge[u][v] = true;
        }
        // 做一次拓扑检测
        vector<int> deg = indeg;
        queue<int> q;
        for (int j = 0; j < n; j++)
        {
            if (deg[j] == 0)
                q.push(j);
        }
        bool unique = true;
        vector<int> res;
        while (!q.empty())
        {
            if (q.size() > 1)
                unique = false;
            int x = q.front();
            q.pop();
            res.push_back(x);
            for (int y : g[x])
            {
                if (--deg[y] == 0)
                    q.push(y);
            }
        }
        if ((int)res.size() < n)
        {
            cout << "Inconsistency found after " << i << " relations.\n";
            return;
        }
        if (unique)
        {
            cout << "Sorted sequence determined after " << i
                 << " relations: ";
            for (int x : res)
                cout << char('A' + x);
            cout << ".\n";
            return;
        }
    }
    cout << "Sorted sequence cannot be determined.\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    #if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    #endif
    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}