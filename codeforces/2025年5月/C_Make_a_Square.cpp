#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const ll inf = 1e9;
const int N = 2e9 + 10;

bool judge(const string &t, const string &num)
{
    int i = 0, j = 0;
    int n = t.size(), m = num.size();
    while (i < n && j < m)
    {
        if (t[i] == num[j])
        {
            j++;
        }
        i++;
    }
    return j == m;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    // string num;
    // cin >> num;
    // int n = num.size();
    // ll ans = inf;

    // for(int i = 1;;i++)
    // {
    //     ll square = i * i * 1LL;
    //     string t = to_string(square);
    //     if (t.size() > n) break;
    //     if (judge(num, t)) {
    //         ans = min(ans, (ll)(n - (int)t.size()));
    //     }
    // }

    // if (ans == inf) {
    //     cout << -1 << endl;
    // } else {
    //     cout << ans << endl;
    // }

    string num;
    cin >> num;
    int n = num.size();
    const int INF = 1e9;
    int ans = INF;
    for (int i = 1;; i++)
    {
        ll sq = 1LL * i * i;
        string s = to_string(sq);
        if ((int)s.size() > n)
            break;
        if (judge(num, s))
        {
            ans = min(ans, n - (int)s.size());
        }
    }

    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}