#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e6 + 10;
const ll mod = 998244353;
#define int long long
int stk[N];
int tt = 0;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    ll sum = 0;
    bool flag = false;

    while (n--)
    {
        string op;
        cin >> op;
        if (op == "Push")
        {
            int x;
            cin >> x;
            stk[tt] = x;
            tt++;
            sum = (sum + x) % mod;
        }
        else if (op == "Pop")
        {
            tt--;
            sum = (sum - stk[tt] + mod) % mod;
        }
        else if (op == "Repeat")
        {
            if (tt <= n)
            {
                int cel = tt;
                for (int i = 0; i < cel; i++)
                {
                    stk[tt] = stk[i];
                    tt++;
                }
            }
            sum = sum * 2 % mod;
        }
        cout << sum << endl;
    }

    return 0;
}