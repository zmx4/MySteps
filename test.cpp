#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        
            vector<int> a(n + 1, 0);
        bool alln = 1;
        int p = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] > 0)
                alln = 0;
        }
        if (n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > 0)
            {
                p = i;
                break;
            }
        }
        if (alln)
        {
            cout << n - 1 << endl;
            for (int i = n - 1; i >= 1; i--)
            {
                cout << i << " " << i + 1 << endl;
            }
            continue;
        }
        cout << 5 + 2 * (n - 1) << endl;
        for (int i = 1; i <= 5; i++)
            cout << p << " " << p << endl;
        
        for (int i = 2; i <= n - 1; i++)
        {
            for (int j = 1; j <= 2; j++)
                cout << i + 1 << " " << i << endl;
        }
    }
    return 0;
}
/*

1 -19 -19 



*/