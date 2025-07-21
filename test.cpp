#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
    vector<int> p, r;
    DSU(int n) : p(n, -1), r(n, 0) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
    }
};

inline void solve()
{
    ll H, W;
    int K;
    cin >> H >> W >> K;
    vector<pair<ll, ll>> obs(K);
    obs.reserve(K);
    for (int i = 0; i < K; i++)
    {
        cin >> obs[i].first >> obs[i].second;
    }
    // Map each obstacle coord to its index
    unordered_map<ll, int> idx;
    idx.reserve(K * 2);
    auto encode = [&](ll r, ll c)
    {
        return (r << 32) ^ c;
    };
    for (int i = 0; i < K; i++)
    {
        idx[encode(obs[i].first, obs[i].second)] = i;
    }
    DSU dsu(K);
    // DSU merge adjacent obstacles
    for (int i = 0; i < K; i++)
    {
        ll r = obs[i].first, c = obs[i].second;
        const ll dr[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dc[8] = {0, 1, 0, -1, 1, -1, 1, -1};
        for (int d = 0; d < 8; d++)
        {
            ll nr = r + dr[d], nc = c + dc[d];
            ll code = encode(nr, nc);
            auto it = idx.find(code);
            if (it != idx.end())
            {
                dsu.unite(i, it->second);
            }
        }
    }
    // Track boundary touches for each component root
    vector<bool> touchTop(K, false), touchBot(K, false);
    vector<bool> touchLeft(K, false), touchRight(K, false);
    for (int i = 0; i < K; i++)
    {
        int rt = dsu.find(i);
        ll r = obs[i].first, c = obs[i].second;
        if (r == 1)
            touchTop[rt] = true;
        if (r == H)
            touchBot[rt] = true;
        if (c == 1)
            touchLeft[rt] = true;
        if (c == W)
            touchRight[rt] = true;
    }
    // Check if any component blocks path
    bool blocked = false;
    for (int i = 0; i < K; i++)
    {
        if (dsu.find(i) == i)
        {
            if ((touchTop[i] && touchBot[i]) || (touchLeft[i] && touchRight[i]) ||
                (touchTop[i] && touchLeft[i]) || (touchBot[i] && touchRight[i]))
            {
                blocked = true;
                break;
            }
        }
    }
    cout << (blocked ? "No\n" : "Yes\n");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}