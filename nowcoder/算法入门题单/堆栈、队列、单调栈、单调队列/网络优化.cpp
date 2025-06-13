#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Interval
{
    int l, r, v, id;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while ((cin >> n >> m))
    {
        vector<Interval> seg(m);
        for (int i = 0; i < m; i++)
        {
            cin >> seg[i].l >> seg[i].r >> seg[i].v;
            seg[i].id = i;
        }
        sort(seg.begin(), seg.end(), [&](auto &A, auto &B)
             { return A.l < B.l; });
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        ll ans = 0;
        int ptr = 0;
        vector<int> rem(m);
        for (int i = 0; i < m; i++)
            rem[i] = seg[i].v;

        for (int j = 1; j <= n; j++)
        {
            while (ptr < m && seg[ptr].l == j)
            {
                pq.emplace(seg[ptr].r, ptr);
                ptr++;
            }
            while (!pq.empty())
            {
                auto [rr, idx] = pq.top();
                if (rr < j || rem[idx] == 0)
                    pq.pop();
                else
                    break;
            }
            if (!pq.empty())
            {
                auto [rr, idx] = pq.top();
                ans++;
                rem[idx]--;
                if (rem[idx] == 0)
                {
                    pq.pop();
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}