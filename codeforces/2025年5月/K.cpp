#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;

    vector<int> nxt(n), pre(n);
    for (int i = 0; i < n; i++)
    {
        nxt[i] = (i + 1) % n;
        pre[i] = (i - 1 + n) % n;
    }

    vector<int> skip(n, 0);

    int cur = 0;
    int dir = +1;

    auto getNext = [&](int u)
    {
        return dir == 1 ? nxt[u] : pre[u];
    };

    for (int i = 0; i < m;)
    {
        if (skip[cur] > 0)
        {
            skip[cur]--;
            cur = getNext(cur);
            continue;
        }
        char c = s[i++];
        a[cur]--;
        int v = getNext(cur);

        if (c == 'S')
        {
            skip[v]++;
        }
        else if (c == 'D')
        {
            a[v] += 2;
            skip[v]++;
        }
        else if (c == 'R')
        {
            dir = -dir;
        }
        if (a[cur] == 0)
        {
            int L = pre[cur], R = nxt[cur];
            nxt[L] = R;
            pre[R] = L;
            cur = dir == 1 ? R : L;
        }
        else
        {
            cur = getNext(cur);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}