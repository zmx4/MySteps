#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
using ll = long long;
using LL = long long;
using i64 = long long;
#define PII pair<int,int>
#define mod 998244353
const int Mod = 1e9+7;
template<typename T>
struct BIT {
    const int n;
    std::vector<T> tree;
    BIT(int n) : n(n), tree(n + 1) {};
    T Query(int x) {
        T res = 0;
        for (int i = x; i > 0; i -= (i & -i)) {
            res += tree[i];
        }
        return res;
    }
    void Modify(int l, T z) {
        if (l <= 0) return;
        for (int i = l; i <= n; i += (i & -i)) {
            tree[i] += z;
        }
    }
    T rangeQuery(int l, int r) {
        return Query(std::min(n, r)) - Query(std::max(0ll, l - 1));
    }
};//树状数组

struct Comb {
    const int N;
    vector<i64> fac, invfac;
    Comb(int n) : N(n), fac(n + 2), invfac(n + 2) { init(); };
    i64 qpow(i64 x, i64 p) {
        i64 res = 1 % mod; x %= mod;
        for (; p; p >>= 1, x = x * x % mod)
            if (p & 1) res = res * x % mod;
        return res;
    }
    i64 inv(i64 x) { return qpow(x, mod - 2); };
    void init() {
        fac[0] = 1;
        for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * i % mod;
        invfac[N] = inv(fac[N]);
        for (int i = N - 1; i >= 0; --i) invfac[i] = (invfac[i + 1] * (i + 1)) % mod;
    }
    i64 C(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac[n] * invfac[m] % mod * invfac[n - m] % mod;
    }
    i64 A(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac[n] * invfac[n - m] % mod;
    }
};//组合数


struct HLD {
    int n, idx;
    vector<int> siz, dep, fa;
    vector<int> dfn, rdfn, top;
    vector<vector<int>> g;

    HLD() {};
    HLD(int _) { init(_); }

    void init(int _) {
        this->n = _;
        dep.resize(_ + 1);
        fa.resize(_ + 1);
        dfn.resize(_ + 1);
        rdfn.resize(_ + 1);
        top.resize(_ + 1);
        siz.assign(_ + 1, 1);
        g.assign(_ + 1, {});
        idx = 0;
    }
    void addEdge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    void DFS1(int u) {
        if (fa[u]) g[u].erase(find(g[u].begin(), g[u].end(), fa[u]));
        for (auto& v : g[u]) {
            fa[v] = u, dep[v] = dep[u] + 1;
            DFS1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[g[u][0]]) {
                swap(v, g[u][0]);
            }
        }
    }
    void DFS2(int u) {
        dfn[u] = ++idx, rdfn[idx] = u;
        for (auto& v : g[u]) {
            top[v] = (v == g[u][0] ? top[u] : v);
            DFS2(v);
        }
    }
    int LCA(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            u = fa[top[u]];
        }
        return dep[u] < dep[v] ? u : v;
    }
    int findson(int u, int ufa) {
        int res;
        if (u == ufa) return u;
        if (dep[top[u]] < dep[top[ufa]]) swap(u, ufa);
        while (top[u] != top[ufa]) {
            res = top[u];
            u = fa[top[u]];
        }
        return u == ufa ? res : g[ufa][0];
    }
    int dist(int u, int v) {
        return dep[u] + dep[v] - (dep[LCA(u, v)] << 1);
    }
    int jump(int u, int k) {
        if (dep[u] < k) return -1;
        int d = dep[u] - k;
        while (dep[top[u]] > d) u = fa[top[u]];
        return rdfn[dfn[top[u]] - dep[top[u]] + d];
    }
    void work(int root = 1) {
        top[root] = root;
        dep[root] = 1;
        DFS1(root), DFS2(root);
    }
};//重链剖分

template<class BS>
struct Hungarian {
    int N1, N2;
    vector<BS> g;
    vector<int> match1, match2;
    vector<int> pre, que;
    BS vis;

    Hungarian(int n, int m) : N1(n), N2(m), g(n), match1(n), match2(m), pre(n), que(n) {}

    void BFS(int S) {
        int l = 0, r = 0;
        que[r++] = S, pre[S] = -1;
        vis.set();
        while (l < r) {
            int u = que[l++];
            auto adj = vis & g[u];
            for (int v = adj._Find_first(); v < N2; v = adj._Find_next(v)) {
                vis[v] = false;
                if (match2[v] != -1) {
                    que[r++] = match2[v];
                    pre[match2[v]] = u;
                    continue;
                }
                int x = u, y = v;
                while (x != -1) {
                    int t = match1[x];
                    match1[x] = y, match2[y] = x, x = pre[x], y = t;
                }
                return;
            }
        }
    }

    vector<PII> hungarian() {
        vector<PII> res;
        match1.assign(N1, -1);
        match2.assign(N2, -1);
        for (int i = 0; i < N1; ++i) {
            if (match1[i] == -1) BFS(i);
        }
        for (int i = 0; i < N1; ++i) {
            if (match1[i] != -1) res.emplace_back(i, match1[i]);
        }
        return res;
    }
};//匈牙利，二分图最大匹配


template<class Info_lazy, class Tag>
struct Segtree {
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r
    int n;
    vector<Info_lazy> info;
    vector<Tag> tag;
    Segtree(int _n) : n(_n), info((_n + 5) << 2), tag((_n + 5) << 2) {};
    Segtree(vector<Info_lazy>& arr) : Segtree(arr.size() - 1) {
        function<void(int, int, int)> build = [&](int k, int l, int r) {
            if (l == r) {
                info[k] = arr[l];
                return;
            }
            int mid = l + r >> 1;
            build(lson), build(rson);
            pushup(k);
        };
        build(1, 1, n);
    }
    void pushdown(int k, int l, int r) {
        int mid = l + r >> 1, lt = k << 1, rt = k << 1 | 1;
        info[lt].down(tag[k], mid - l + 1);
        info[rt].down(tag[k], r - mid);
        tag[lt].down(tag[k]);
        tag[rt].down(tag[k]);
        tag[k] = Tag();//初始化tag
    }
    void pushup(int k) {
        info[k] = merge(info[k << 1], info[k << 1 | 1]);
    }
    void Modify(int k, int l, int r, int x, int y, const Tag& z) {
        if (l >= x && r <= y) {
            info[k].down(z, r - l + 1);
            tag[k].down(z);
            return;
        }
        if (tag[k].change()) pushdown(k, l, r);
        int mid = l + r >> 1;
        if (x <= mid) Modify(lson, x, y, z);
        if (y > mid) Modify(rson, x, y, z);
        pushup(k);
    }
    Info_lazy Query(int k, int l, int r, int x, int y) {
        if (l >= x && r <= y) return info[k];
        if (tag[k].change()) pushdown(k, l, r);
        int mid = l + r >> 1;
        if (y <= mid) return Query(lson, x, y);
        if (x > mid) return Query(rson, x, y);
        return merge(Query(lson, x, y), Query(rson, x, y));
    }
    void Modify(int l, int r, const Tag& z) {
        Modify(1, 1, n, l, r, z);
    }
    Info_lazy Query(int l, int r) {
        return Query(1, 1, n, l, r);
    }
};

struct Tag {
    int val;
    bool change() { return val != 0; }
    void down(const Tag& t) {
        //标记下放
        val += t.val;
    }
};

struct Info_lazy {
    i64 sum;
    void down(const Tag& t, int len) {
        //标记下放
        sum += t.val * len;
    }
    friend Info_lazy merge(const Info_lazy& a, const Info_lazy& b) {
        Info_lazy res;
        res.sum = a.sum + b.sum;
        return res;
    }
};//懒标
// Apply(l, r, Tag) 用Tag修改区间 [l, r]
// Query(l, r) 返回区间 [l, r] 的Info信息

template<class Ty>
struct maxFlow {
    const Ty INF = numeric_limits<Ty>::max();
    const int inf = INT32_MAX;
    int S, T, n; Ty MF = 0;
    struct Edge {
        int v, nxt; Ty f;
        Edge() : Edge(0, 0, 0) {};
        Edge(int v, int nxt, Ty f) : v(v), nxt(nxt), f(f) {};
    };

    vector<int> dist, cur, h;
    vector<Edge> E;

    maxFlow(int _) : n(_) { init(_); };

    void init(int _) {
        dist.resize(_ + 1);
        cur.resize(_ + 1);
        h.resize(_ + 1);
        E.resize(2);
    }

    void add(int u, int v, Ty f) {
        E.emplace_back(v, h[u], f), h[u] = int(E.size()) - 1;
    }

    void addEdge(int u, int v, Ty f) {
        add(u, v, f), add(v, u, 0);
    }

    bool BFS() {
        dist.assign(n + 1, inf);
        queue<int> que;
        dist[S] = 0, cur[S] = h[S];
        que.push(S);
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int i = h[u]; i; i = E[i].nxt) {
                auto& [v, nxt, f] = E[i];
                if (f && dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    cur[v] = h[v];
                    if (v == T) return true;
                    que.push(v);
                }
            }
        }
        return false;
    }

    Ty DFS(int u, Ty flow) {
        if (u == T) return flow;
        Ty last = flow;
        for (int i = cur[u]; i && last; i = E[i].nxt) {
            cur[u] = i;
            auto& [v, nxt, f] = E[i];
            if (f && dist[v] == dist[u] + 1) {
                Ty cost = DFS(v, min(f, last));
                if (!cost) dist[v] = INF;
                E[i].f -= cost, E[i ^ 1].f += cost;
                last -= cost;
            }
        }
        return flow - last;
    }

    void work() {
        while (BFS()) {
            Ty flow = DFS(S, INF);
            MF += flow;
        }
    }
};//最大流

template<class Ty>
struct MCmaxFlow {
    const Ty INF = numeric_limits<Ty>::max();
    int S, T, n; Ty MF = 0, MC = 0;
    struct Edge {
        int v, nxt; Ty f, w;
        Edge() : Edge(0, 0, 0, 0) {};
        Edge(int v, int nxt, Ty f, Ty w) : v(v), nxt(nxt), f(f), w(w) {};
    };

    vector<Ty> dist;
    vector<int> cur, h;
    vector<bool> vis;
    vector<Edge> E;

    MCmaxFlow(int _) : n(_) { init(_); };

    void init(int _) {
        dist.resize(_ + 1);
        vis.resize(_ + 1);
        cur.resize(_ + 1);
        h.resize(_ + 1);
        E.resize(2);
    }

    void add(int u, int v, Ty f, Ty w) {
        E.emplace_back(v, h[u], f, w), h[u] = int(E.size()) - 1;
    }

    void addEdge(int u, int v, Ty f, Ty w) {
        add(u, v, f, w), add(v, u, 0, -w);
    }

    bool SPFA() {
        dist.assign(n + 1, INF);
        queue<int> que;
        dist[S] = 0, cur[S] = h[S];
        que.push(S);
        while (que.size()) {
            int u = que.front(); que.pop();
            vis[u] = false;
            for (int i = h[u]; i; i = E[i].nxt) {
                auto& [v, nxt, f, w] = E[i];
                if (f && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    if (!vis[v]) {
                        vis[v] = true;
                        cur[v] = h[v];
                        que.push(v);
                    }
                }
            }
        }
        return dist[T] != INF;
    }

    Ty DFS(int u, Ty flow) {
        if (u == T) return flow;
        Ty last = flow;
        vis[u] = true;
        for (int i = cur[u]; i && last; i = E[i].nxt) {
            cur[u] = i;
            auto& [v, nxt, f, w] = E[i];
            if (f && !vis[v] && dist[v] == dist[u] + w) {
                Ty cost = DFS(v, min(f, last));
                if (!cost) dist[v] = INF;
                E[i].f -= cost, E[i ^ 1].f += cost;
                last -= cost;
            }
        }
        vis[u] = false;
        return flow - last;
    }

    void work() {
        while (SPFA()) {
            Ty flow = DFS(S, INF);
            MC += dist[T] * flow;
            MF += flow;
        }
    }
};//最小费用最大流

struct RoundSquareTree {
    int n, VDCC, idx;
    vector<vector<int>> g;
    vector<int> dfn, low, stk;
    vector<PII> edges;

    RoundSquareTree() {}
    RoundSquareTree(int _) { init(_); }

    void init(int _) {
        this->n = _;
        g.assign(_ + 1, {});
        dfn.resize(_ + 1);
        low.resize(_ + 1);
        edges.clear();
        stk.clear();
        VDCC = idx = 0;
    }
    void addEdge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    void Tarjan(int u) {
        dfn[u] = low[u] = ++idx;
        stk.emplace_back(u);
        for (auto& v : g[u]) {
            if (!dfn[v]) {
                Tarjan(v);
                low[u] = min(low[u], low[v]);
                if (low[v] >= dfn[u]) {
                    ++VDCC; int top = -1;
                    while (top != v) {
                        top = stk.back(); stk.pop_back();
                        edges.emplace_back(top, n + VDCC);
                    }
                    edges.emplace_back(u, n + VDCC);
                }
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
    pair<int, vector<PII>> work() {
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {
                Tarjan(i);
                stk.clear();
            }
        }
        return {VDCC, edges};
    }
};//仙人掌树

struct SCC {
    int n, c_scc, idx;
    vector<int> stk;
    vector<int> dfn, low, scc, siz;
    vector<vector<int>> g;

    SCC() {};
    SCC(int _) { init(_); }

    void init(int _) {
        this->n = _;
        g.assign(_ + 1, {});
        dfn.resize(_ + 1);
        low.resize(_ + 1);
        scc.resize(_ + 1);
        siz.resize(1);
        stk.clear();
        idx = c_scc = 0;
    }
    void addEdge(int u, int v) {
        g[u].emplace_back(v);
    }
    void DFS(int u) {
        dfn[u] = low[u] = ++idx;
        stk.emplace_back(u);
        for (auto& v : g[u]) {
            if (!dfn[v]) {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
            else if (!scc[v]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            int top = -1, cnt = 0; ++c_scc;
            while (top != u) {
                top = stk.back(); stk.pop_back();
                scc[top] = c_scc; ++cnt;
            }
            siz.emplace_back(cnt);
        }
    }
    void work() {
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) DFS(i);
        }
    }
};//缩点

template<class Info>
struct Segtree {
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r
    int n;
    vector<Info> info;
    Segtree(int _n) : n(_n), info((_n + 5) << 2) {};
    Segtree(vector<Info>& arr) : Segtree(arr.size() - 1) {
        function<void(int, int, int)> build = [&](int k, int l, int r) {
            if (l == r) {
                info[k] = arr[l];
                return;
            }
            int mid = l + r >> 1;
            build(lson), build(rson);
            pushup(k);
        };
        build(1, 1, n);
    }
    void pushup(int k) {
        info[k] = merge(info[k << 1], info[k << 1 | 1]);
    }
    void Modify(int k, int l, int r, int x, Info& z) {
        if (l == r) return void(info[k] = z);
        int mid = l + r >> 1;
        if (x <= mid) Modify(lson, x, z);
        if (x > mid) Modify(rson, x, z);
        pushup(k);
    }
    Info Query(int k, int l, int r, int x, int y) {
        if (l >= x && r <= y) return info[k];
        int mid = l + r >> 1;
        if (y <= mid) return Query(lson, x, y);
        if (x > mid) return Query(rson, x, y);
        return merge(Query(lson, x, y), Query(rson, x, y));
    }
    void Modify(int pos, Info& z) {
        Modify(1, 1, n, pos, z);
    }
    Info Query(int l, int r) {
        return Query(1, 1, n, l, r);
    }
};

struct Info {
    int sum;
    friend Info merge(const Info& a, const Info& b) {
        Info res;
        res.sum = a.sum + b.sum;
        return res;
    }
};

struct DSU2 {
    vector<int> fa, siz;
    vector<i64> dis;
    DSU2(int n) : fa(n + 1), siz(n + 1, 1), dis(n + 1) { iota(fa.begin(), fa.end(), 0); };
    function<int(int)> find = [&](int x) {
        if (x == fa[x]) return x;
        find(fa[x]); dis[x] += dis[fa[x]];
        return fa[x] = fa[fa[x]];
    };
    int size(int x) { return siz[find(x)]; }
    i64 dist(int x, int y) {
        int xf = find(x), yf = find(y);
        if (xf != yf) return -1;
        return dis[x] + -dis[y];
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y, i64 w) {
        int xf = find(x), yf = find(y);
        if (xf == yf) return false;
        siz[yf] += siz[xf]; fa[xf] = yf;
        dis[xf] = -dis[x] + w + dis[y];
        return true;
    }
};//带权查询并查集

//自定义第二维长度
template <const int M>
struct Trie {
    vector<array<int, M>> trie;
    vector<bool> exist;
    vector<int> cnt;

    Trie() { init(); }
    void init() {
        trie.emplace_back(array<int, M>{});
        exist.resize(1);
        cnt.resize(1);
    }
    void insert(const string& str) {
        int now = 0, p;
        for (auto& c : str) {
            p = Pos(c);
            if (!trie[now][p]) {
                trie[now][p] = trie.size();
                trie.emplace_back(array<int, M>{});
                exist.emplace_back(false);
                cnt.emplace_back(0);
            }
            now = trie[now][p];
            ++cnt[now];
        }
        exist[now] = true;
    }
    int Querypre(const string& str) {
        int now = 0, p;
        for (auto& c : str) {
            p = Pos(c);
            if (!trie[now][p]) {
                return 0;
            }
            now = trie[now][p];
        }
        return cnt[now];
    }
    bool Querystr(const string& str) {
        int now = 0, p;
        for (auto& c : str) {
            p = Pos(c);
            if (!trie[now][p]) {
                return false;
            }
            now = trie[now][p];
        }
        return exist[now];
    }
    int Pos(char ch) {
        //自定义位置参数
        if (ch >= 'a' && ch <= 'z') return ch - 'a';
        if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 26;
        if (ch >= '0' && ch <= '9') return ch - '0' + 52;
    }
};//动态开店trie

// template <int T>
// struct MInt {
//     constexpr static int MD = T;
//     int x;
//     MInt() : x(0) {}
//     MInt(int _) : x(norm(_ % MD)) {}
//     MInt(i64 _) : x(norm(_ % MD)) {}
//     MInt(double _) : MInt(i64(_)) {}
//     constexpr int norm(int a) const {
//         if (a >= MD) a = a - MD;
//         if (a < 0) a = a + MD;
//         return a;
//     }
//     constexpr int get() const { return x; }
//     constexpr MInt operator+(const MInt& that) const {
//         return MInt(norm(x + that.x));
//     }
//     constexpr MInt operator-(const MInt& that) const {
//         return MInt(norm(x - that.x));
//     }
//     constexpr MInt operator*(const MInt& that) const {
//         return MInt((i64)x * that.x % MD);
//     }
//     constexpr MInt operator-() const { return MInt(norm(-x)); }
//     constexpr MInt operator/(const MInt& that) const {
//         assert(that.x != 0);
//         return *this * that.inverse();
//     }
//     constexpr MInt inverse() const {
//         int a = x, b = MD, u = 1, v = 0;
//         while (b) {
//             int t = a / b;
//             std::swap(a -= t * b, b);
//             std::swap(u -= t * v, v);
//         }
//         return norm(u);
//     }
//     void operator+=(const MInt& that) { x = norm(x + that.x); }
//     void operator-=(const MInt& that) { x = norm(x - that.x); }
//     void operator*=(const MInt& that) { x = norm((i64)x * that.x % MD); }
//     void operator/=(const MInt& that) { *this = *this / that; }
//     void operator--() { x = norm(x - 1); }
//     void operator++() { x = norm(x + 1); }
//     friend constexpr bool operator<(const MInt& A, const MInt& B) { return A.get() < B.get(); }
//     friend constexpr bool operator>(const MInt& A, const MInt& B) { return A.get() > B.get(); }
//     friend constexpr bool operator<=(const MInt& A, const MInt& B) { return A.get() <= B.get(); }
//     friend constexpr bool operator>=(const MInt& A, const MInt& B) { return A.get() >= B.get(); }
//     friend constexpr bool operator==(const MInt& A, const MInt& B) { return A.get() == B.get(); }
//     friend constexpr bool operator!=(const MInt& A, const MInt& B) { return A.get() != B.get(); }
//     friend constexpr std::istream& operator>>(istream &is, MInt& A) {
//         i64 v; is >> v;
//         A = MInt(v); return is;
//     }
//     friend constexpr std::ostream& operator<<(ostream& os, const MInt& x) {
//         return os << x.get();
//     }
// };
// constexpr int mod = 1e9 + 7;
// using Mint = MInt<mod>;

template <class Ty, const int logn>
struct SparseTable {
    vector<array<Ty, logn>> info;

    SparseTable(const vector<Ty>& A) { init(A); }
    void init(const vector<Ty>& A) {
        int n = A.size() - 1;
        info.assign(A.size(), array<Ty, logn>{});
        for (int i = 1; i <= n; ++i) {
            info[i][0] = A[i];
        }
        for (int j = 1; j <= logn; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                info[i][j] = merge(info[i][j - 1], info[i + (1 << j - 1)][j - 1]);
            }
        }
    }
    Ty Query(int l, int r) {
        int j = __lg(r - l + 1);
        return merge(info[l][j], info[r - (1 << j) + 1][j]);
    };
    constexpr Ty merge(const Ty& a, const Ty& b) {
        //自定义信息合并方式
        return max(a, b);
    }
};//ST表板子

template<class Ty>
struct CartesianTree {
    vector<int> stk;
    vector<int> L, R;
    CartesianTree() {}
    tuple<int, vector<int>, vector<int>> work(const vector<Ty>& A) {
        L.assign(A.size(), 0), R.assign(A.size(), 0);
        int n = A.size() - 1;
        for (int i = 1; i <= n; ++i) {
            int lst = 0;
            while (stk.size() && A[stk.back()] > A[i]) {
                lst = stk.back();
                stk.pop_back();
            }
            if (stk.size()) {
                R[stk.back()] = i;
            }
            if (lst) {
                L[i] = lst;
            }
            stk.emplace_back(i);
        }
        return {stk[0], L, R};
    }
};//笛卡尔树

template<class Ty, const int M>
struct Basis {
    Ty a[M] {};
    bool insert(Ty x) {
        for (Ty i = M - 1; i >= 0; --i) {
            if (x >> i & 1) {
                if (!a[i]) return a[i] = x, true;
                x ^= a[i];
            }
        }
        return false;
    }
    bool check(Ty x) {
        for (Ty i = M - 1; i >= 0; --i) {
            if (x >> i & 1) x ^= a[i];
        }
        return x == 0;
    }
    Ty Query() {
        Ty res = 0;
        for (Ty i = M - 1; i >= 0; --i) {
            res = max(res, res ^ a[i]);
        }
        return res;
    }
};//线性基

template<class T>
struct BlockArray {
    i64 Len, Bnum;
    vector<T> info;
    vector<int> pos, L, R;
    BlockArray(const vector<T>& a) { init(a); }

    void init(const vector<T>& a) {
        int N = a.size() - 1;
        Len = sqrt(N);
        Bnum = (N + Len - 1) / Len;
        pos.resize(N + 1);
        L.resize(Bnum + 1);
        R.resize(Bnum + 1);
        info.resize(Bnum + 1);
        for (int i = 1; i <= Bnum; ++i) {
            L[i] = R[i - 1] + 1, R[i] = i * Len;
        }
        R[Bnum] = N;
        for (int i = 1; i <= Bnum; ++i) {
            for (int j = L[i]; j <= R[i]; ++j) {
                pos[j] = i;
                //处理信息
            }
        }
    }

    void Modify(int l, int r) {
        int lb = pos[l], rb = pos[r];
        if (lb == rb) {
            for (int i = l; i <= r; ++i) {
                //块内
            }
            return;
        }
        //整散块
        for (int i = lb + 1; i <= rb - 1; ++i) {

        }
        for (int i = l; i <= R[lb]; ++i) {

        }
        for (int i = r; i >= L[rb]; --i) {

        }
    }

    T Query(int l, int r) {
        int lb = pos[l], rb = pos[r];
        T res;
        if (lb == rb) {
            for (int i = l; i <= r; ++i) {
                //块内
            }
            return res;
        }
        //整散块
        for (int i = lb + 1; i <= rb - 1; ++i) {

        }
        for (int i = l; i <= R[lb]; ++i) {

        }
        for (int i = r; i >= L[rb]; --i) {

        }
        return res;
    }
};//块状数组

template<const int N>
struct StringHash {
    using i64 = long long;
   // using PII = std::pair<int, int>;
    const int mod1 = 1e9 + 97, mod2 = 998244853, p1 = 131, p2 = 233;
    std::array<int, N> a1, a2;
    std::array<int, N> Phs1, Phs2;
    std::array<int, N> Shs1, Shs2;//如果不判回文 删掉后缀哈希可以减小一半常数
    StringHash() {
        init(N - 1);
    }
    StringHash(const std::string& S) {
        init(N - 1);
        work(S);
    }
    // All of the Working progress is 0-idxed [0, 1, 2, ..., n - 1]
    void work(const std::string& s) {
        int n = s.size();
        assert(n + 1 <= N);
        for (int i = 0; i < n; ++i) {
            int t = n - i - 1;
            Phs1[i + 1] = ((i64)Phs1[i] * p1 + s[i]) % mod1;
            Phs2[i + 1] = ((i64)Phs2[i] * p2 + s[i]) % mod2;
            Shs1[t + 1] = ((i64)Shs1[t + 2] * p1 + s[t]) % mod1;//如果不判回文 删掉后缀哈希可以减小一半常数
            Shs2[t + 1] = ((i64)Shs2[t + 2] * p2 + s[t]) % mod2;//如果不判回文 删掉后缀哈希可以减小一半常数
        }
    }
    // All of the Query is 1-idxed [1, 2, 3, ..., n]
    PII PreHash(int l, int r) {
        assert(l <= r);
        int P1 = (Phs1[r] - (i64)Phs1[l - 1] * a1[r - l + 1] % mod1 + mod1) % mod1;
        int P2 = (Phs2[r] - (i64)Phs2[l - 1] * a2[r - l + 1] % mod2 + mod2) % mod2;
        return PII(P1, P2);
    };
    PII SufHash(int l, int r) {
        assert(l <= r);
        int S1 = (Shs1[l] - (i64)Shs1[r + 1] * a1[r - l + 1] % mod1 + mod1) % mod1;
        int S2 = (Shs2[l] - (i64)Shs2[r + 1] * a2[r - l + 1] % mod2 + mod2) % mod2;
        return PII(S1, S2);
    }
    bool isPlalindrome(int l, int r) {
        auto [P1, P2] = PreHash(l, r);
        auto [S1, S2] = SufHash(l, r);
        return P1 == S1 && P2 == S2;
    }
    void init(int n) {
        a1[0] = a2[0] = 1;
        for (int i = 0; i < n; ++i) {
            a1[i + 1] = (i64)a1[i] * p1 % mod1;
            a2[i + 1] = (i64)a2[i] * p2 % mod2;
        }
    }
};//字符串哈希

i64 mul(i64 a, i64 b, i64 m) {
    return static_cast<__int128>(a) * b % m;
}
i64 power(i64 a, i64 b, i64 m) {
    i64 res = 1 % m;
    for (; b; b >>= 1, a = mul(a, a, m))
        if (b & 1)
            res = mul(res, a, m);
    return res;
}
bool isprime(i64 n) {
    if (n < 2)
        return false;
    static constexpr int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    int s = __builtin_ctzll(n - 1);
    i64 d = (n - 1) >> s;
    for (auto a : A) {
        if (a == n)
            return true;
        i64 x = power(a, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool ok = false;
        for (int i = 0; i < s - 1; ++i) {
            x = mul(x, x, n);
            if (x == n - 1) {
                ok = true;
                break;
            }
        }
        if (!ok)
            return false;
    }
    return true;
}
std::vector<i64> factorize(i64 n) {
    std::vector<i64> p;
    auto f = [&](auto self, i64 n) {
        if (n <= 10000) {
            for (int i = 2; i * i <= n; ++i)
                for (; n % i == 0; n /= i)
                    p.push_back(i);
            if (n > 1)
                p.push_back(n);
            return;
        }
        if (isprime(n)) {
            p.push_back(n);
            return;
        }
        auto g = [&](i64 x) {
            return (mul(x, x, n) + 1) % n;
        };
        i64 x0 = 2;
        while (true) {
            i64 x = x0;
            i64 y = x0;
            i64 d = 1;
            i64 power = 1, lam = 0;
            i64 v = 1;
            while (d == 1) {
                y = g(y);
                ++lam;
                v = mul(v, std::abs(x - y), n);
                if (lam % 127 == 0) {
                    d = std::gcd(v, n);
                    v = 1;
                }
                if (power == lam) {
                    x = y;
                    power *= 2;
                    lam = 0;
                    d = std::gcd(v, n);
                    v = 1;
                }
            }
            if (d != n) {
                self(self, d);
                self(self, n / d);
                return;
            }
            ++x0;
        }
    };
    f(f, n);
    std::sort(p.begin(), p.end());
    return p;
}//质因子分解

struct SAM {
    static constexpr int ALPHABET_SIZE = 26;
    struct Node {
        int len, link, cnt;
        std::array<int, ALPHABET_SIZE> next;
        Node() : len{}, cnt{}, link{}, next{} {}
    };
    std::vector<Node> T;
    SAM() { init(); }
    // Node ranges -> [1, size]
    void init() {
        T.assign(2, Node());
    }
    int newNode() {
        T.emplace_back();
        return (int)T.size() - 1;
    }
    int extend(int p, int c) {
        int lst = p;
        p = newNode();
        lenth(p) = lenth(lst) + 1; count(p) = 1;
        for (; lst && !next(lst, c); lst = link(lst)) {
            next(lst, c) = p;
        }
        if (lst == 0) {
            link(p) = 1;
        } else {
            int u = next(lst, c);
            if (lenth(lst) + 1 == lenth(u)) {
                link(p) = u;
            } else {
                int v = newNode();
                T[v].next = T[u].next;
                link(v) = link(u);
                link(u) = link(p) = v;
                lenth(v) = lenth(lst) + 1;
                for (; lst && next(lst, c) == u; lst = link(lst)) {
                    next(lst, c) = v;
                }
            }
        }
        return p;
    }
    int& link(int p) {
        return T[p].link;
    }
    int& lenth(int p) {
        return T[p].len;
    }
    int& next(int p, int c) {
        return T[p].next[c];
    }
    int& count(int p) {
        return T[p].cnt;
    }
    int size() {
        return (int)T.size() - 1;
    }
};//后缀自动机

struct GSAM {
    static constexpr int ALPHABET_SIZE = 26;
    struct Node {
        int len, link, cnt;
        std::array<int, ALPHABET_SIZE> next;
        Node() : len{}, cnt{}, link{}, next{} {}
    };
    std::vector<Node> T;
    GSAM() { init(); }
    // Node ranges -> [1, size]
    void init() {
        T.assign(2, Node());
    }
    int newNode() {
        T.emplace_back();
        return (int)T.size() - 1;
    }
    int extend(int p, int c) {
        if (next(p, c) && lenth(next(p, c)) == lenth(p) + 1) {
            return next(p, c);
        }
        int lst = p;
        p = newNode();
        lenth(p) = lenth(lst) + 1; count(p) = 1;
        for (; lst && !next(lst, c); lst = link(lst)) {
            next(lst, c) = p;
        }
        if (lst == 0) {
            link(p) = 1;
        } else {
            int u = next(lst, c);
            if (lenth(lst) + 1 == lenth(u)) {
                link(p) = u;
            } else {
                if (lenth(lst) + 1 == lenth(p)) {
                    T.pop_back();
                    p = -1;
                }
                int v = newNode();
                T[v].next = T[u].next;
                link(v) = link(u);
                link(u) = v;
                lenth(v) = lenth(lst) + 1;
                for (; lst && next(lst, c) == u; lst = link(lst)) {
                    next(lst, c) = v;
                }
                if (p == -1) {
                    return v;
                } else {
                    link(p) = v;
                }
            }
        }
        return p;
    }
    int& link(int p) {
        return T[p].link;
    }
    int& lenth(int p) {
        return T[p].len;
    }
    int& next(int p, int c) {
        return T[p].next[c];
    }
    int& count(int p) {
        return T[p].cnt;
    }
    int size() {
        return (int)T.size() - 1;
    }
};//广义自动机

struct ACAM {
    static constexpr int ALPHABET_SIZE = 26;
    struct Node {
        int len, link, cnt;
        std::array<int, ALPHABET_SIZE> next;
        Node() : len{}, cnt{}, link{}, next{} {}
    };
    std::vector<Node> T;
    // Node ranges -> [0, size]
    ACAM() { init(); }
    void init() {
        T.assign(1, Node());
    }
    int newNode() {
        T.emplace_back();
        return (int)T.size() - 1;
    }
    int extend(const std::string& s) {
        int p = 0;
        for (auto& c : s) {
            int v = c - 'a';
            if (next(p, v) == 0) {
                next(p, v) = newNode();
                lenth(next(p, v)) = lenth(p) + 1;
            }
            p = next(p, v);
        }
        ++count(p);
        return p;
    }
    void work() {
        std::queue<int> q;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (next(0, i)) {
                q.emplace(next(0, i));
            }
        }
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                if (next(u, i) == 0) {
                    next(u, i) = next(link(u), i);
                } else {
                    link(next(u, i)) = next(link(u), i);
                    q.emplace(next(u, i));
                }
            }
        }
    }
    int& link(int p) {
        return T[p].link;
    }
    int& lenth(int p) {
        return T[p].len;
    }
    int& next(int p, int c) {
        return T[p].next[c];
    }
    int& count(int p) {
        return T[p].cnt;
    }
    int size() {
        return (int)T.size() - 1;
    }
};//AC自动机
template<typename com>
struct FFT {
    int tot;
    int digit;
    std::vector<int> rev;

    FFT() {}
    FFT(int n) { init(n); }

    // 初始化位逆序置换表和变换长度
    void init(int n) {
        tot = 1;
        digit = 0;
        while (tot < n) {
            tot <<= 1;
            digit++;
        }
        rev.resize(tot);
        for (int i = 0; i < tot; ++i) {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (digit - 1));
        }
    }

    // 执行 FFT 变换
    void fft(std::vector<com>& A, int f) {
        for (int i = 0; i < tot; ++i) {
            if (i < rev[i]) std::swap(A[i], A[rev[i]]);
        }
        for (int mid = 1; mid < tot; mid <<= 1) {
            com w1 = std::polar(1.0, f * M_PI / mid);
            int len = mid * 2;
            for (int p = 0; p < tot; p += len) {
                com wk = 1;
                for (int k = 0; k < mid; ++k) {
                    com x = A[p + k], y = wk * A[p + k + mid];
                    A[p + k] = x + y;
                    A[p + k + mid] = x - y;
                    wk *= w1;
                }
            }
        }
        if (f == -1) {
            for (int i = 0; i < tot; ++i) {
                A[i] /= tot;
            }
        }
    }

    // 计算两个多项式的卷积
    std::vector<com> multiply(const std::vector<com>& a, const std::vector<com>& b) {
        int len = a.size() + b.size() - 1;
        init(len);

        std::vector<com> A = a, B = b;
        A.resize(tot);
        B.resize(tot);

        fft(A, 1);
        fft(B, 1);
        for (int i = 0; i < tot; ++i) {
            A[i] *= B[i];
        }
        fft(A, -1);

        A.resize(len);
        return A;
    }
};//用Complex类型
void solve() {

}
signed main() {
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
    }
}





























