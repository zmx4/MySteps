#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10, M = 5e6 + 10;
int h[N], e[M], ne[M], w[M], idx;
void addedge(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}
int dist[N];
bool st[N];
void solve()
{
    int n, m, c;
    cin >> n >> m >> c;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++)
    {
        int f, t, v;
        cin >> f >> t >> v;
        addedge(f, t, v);
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n; j<<= 1)
        {
            if ((i ^ j) > n)
                continue;
            addedge(i, (i ^ j), j * c);
        }
    }
    memset(dist, 0x3f, sizeof dist);
    int s, t;
    cin >> s >> t;
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (st[u])
            continue; // 修改这里
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[u] + w[i])
            {
                dist[j] = dist[u] + w[i];
                if (!st[j])
                    pq.push({dist[j], j});
            }
        }
    }
    cout << dist[t] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}