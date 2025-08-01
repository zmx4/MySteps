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

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    string ans = "";
    bool first = true;
    for (int i = 0; i <= n; i++)
    {
        int coef = a[i];
        int deg = n - i;
        if (coef == 0)
            continue;
        if (first)
        {
            if (coef < 0)
                ans += '-';
        }
        else
        {
            ans += (coef > 0 ? '+' : '-');
        }
        int abscoef = abs(coef);
        if (deg == 0 || abscoef != 1)
        {
            ans += to_string(abscoef);
        }
        if (deg > 1)
        {
            ans += 'x';
            ans += '^';
            ans += to_string(deg);
        }
        else if (deg == 1)
        {
            ans += 'x';
        }

        first = false;
    }
    cout << ans << endl;
    return 0;
}