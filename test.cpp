#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU
{
    vector<int> p, r;
    DSU(int n) : p(n + 1), r(n + 1, 0)
    {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x)
    {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (r[a] < r[b])
            swap(a, b);
        p[b] = a;
        if (r[a] == r[b])
            r[a]++;
        return true;
    }
    void merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        p[x] = y;
    }
};

inline void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    cout << *s.begin() << endl;
    cout << *s.rbegin() << endl;
    solve();
    return 0;
}