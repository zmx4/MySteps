#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n,m;
    while (cin >> n >> m)
    {
        for (int i = n; i <= m; ++i)
        {
            bitset<6> a(i);
            cout << a << endl;
        }
    }

    return 0;
}