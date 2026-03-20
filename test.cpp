#include <bits/stdc++.h>
using namespace std;
#define int long long
#define eb emplace_back
const int N = 2e5 + 10;
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int a[N];
void run()
{
    int T = read(), ca = 1;
    while (T--)
    {
        int n = read();
        for (int i = 1; i <= n; ++i)
            a[i] = read();
        set<int> buc[3];
        for (int i = 1; i <= n; ++i)
            if (a[i] == 0)
                buc[0].insert(i);
            else if (a[i] == 1)
                buc[1].insert(i);
            else
                buc[2].insert(i);
        auto chk = [&](void)
        {
            int cnt = 0;
            vector<int> id;
            for (int i = 0; i < 3; ++i)
                if (buc[i].size())
                    ++cnt, id.eb(i);
            if (cnt == 1)
                return 1;
            else if (cnt == 2)
            {
                if (*buc[id[0]].rbegin() < *buc[id[1]].begin())
                    return 1;
                return 0;
            }
            else
            {
                if (*buc[0].rbegin() < *buc[1].begin() && *buc[1].rbegin() < *buc[2].begin())
                    return 1;
                return 0;
            }
        };
        vector<pair<int, int>> op;
        while (!chk())
        {
            if (buc[0].size() && buc[1].size())
            {
                int x = *buc[0].rbegin(), y = *buc[1].begin();
                if (x > y)
                {
                    op.eb(x, y);
                    buc[0].erase(x);
                    buc[1].erase(y);
                    buc[0].insert(y);
                    buc[1].insert(x);
                }
            }
            if (chk())
                break;
            if (buc[1].size() && buc[2].size())
            {
                int x = *buc[1].rbegin(), y = *buc[2].begin();
                if (x > y)
                {
                    op.eb(x, y);
                    buc[1].erase(x);
                    buc[2].erase(y);
                    buc[1].insert(y);
                    buc[2].insert(x);
                }
            }
        }
        cout << op.size() << '\n';
        for (auto &[x, y] : op)
            cout << x << ' ' << y << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    run();
    return 0;
}