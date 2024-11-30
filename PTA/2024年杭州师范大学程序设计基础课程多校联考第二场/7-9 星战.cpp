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

int a[500][500];

signed main()
{
    int n, x, y;
    int cnt = 0;
    cin >> n >> x >> y;
    x += 200;
    y += 200;
    while (n--)
    {
        int xx, yy;
        cin >> xx >> yy;
        xx += 200;
        y += 200;
        int u = gcd(xx, yy);
        a[xx / u][yy / u]++;
        if (a[(xx / u)][(yy / u)] <= 1)
            cnt++;
    }
    cout << cnt;
}