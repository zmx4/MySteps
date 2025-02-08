#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;
    string a, b, c;
    cin >> a >> b >> c;
    /*
    100
    110
    010
    */
    ll cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; i++)
    {
        int t1 = a[i] - '0', t2 = b[i] - '0', t3 = c[i] - '0';
        int res = t1 ^ t2;
        if (res == t3)
            continue;

        if (t3 == 0)
        {
            if (t1 == 0 && t2 == 1)
                cnt1++;
            else if (t1 == 1 && t2 == 0)
                cnt2++;
        }
        else if (t1 == t2)
        {
            cnt3++;
        }
    }

    ll ans = cnt3 * x;
    ll minC = min(cnt1, cnt2);
    ans += minC * min(2 * x, y);
    ans += (cnt1 + cnt2 - 2 * minC) * x;

    cout << ans << endl;
    return 0;
}