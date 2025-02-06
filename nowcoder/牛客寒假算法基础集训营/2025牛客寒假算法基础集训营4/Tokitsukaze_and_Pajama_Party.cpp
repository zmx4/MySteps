#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;

    vector<int> qz(n, 0);
    qz[0] = (str[0] == 'u');
    for (int i = 1; i < n; i++)
    {
        qz[i] = qz[i - 1] + (str[i] == 'u');
    }

    ll ans = 0;
    for (int p = 0; p <= n - 8; p++)
    {
        if (str.substr(p, 8) == "uwawauwa")
        {
            if (p - 2 >= 0)
                ans += qz[p - 2];
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}