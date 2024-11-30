#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int a[1000][1000] = {0};

signed main()
{
    int n, x, y;
    cin >> n >> x >> y;
    x += 2000;
    y += 2000;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int xx, yy;
        cin >> xx >> yy;
        xx += 2000;
        yy += 2000;
        int dx = xx - x;
        int dy = yy - y;
        int u = gcd(abs(dx), abs(dy));
        if (u == 0)
            u = 1;
        dx /= u;
        dy /= u;
        if (a[dx + 2000][dy + 2000] == 0)
        {
            cnt++;
        }
        a[dx + 2000][dy + 2000]++;
    }

    cout << cnt << endl;
    return 0;
}