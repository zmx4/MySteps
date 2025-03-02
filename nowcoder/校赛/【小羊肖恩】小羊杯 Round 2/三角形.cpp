#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i; j < 3; j++)
        {
            for (int k = j; k < 3; k++)
            {
                int x = a[i], y = a[j], z = a[k];
                if (x + y > z)
                    cnt++;
            }
        }
    }
    cout << cnt << endl;
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