#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

void solve()
{
    int n,m;cin >> n >> m;
    int b = 0, w = 0;
    bool flag = false;
    while(n >1 && m > 1)
    {
        if(!flag)
        {
            b += 2 * n + (m - 2) * 2;
            n -= 2;
            m -= 2;
            flag = true;
        }
        else
        {
            w += 2 * n + (m - 2) * 2;
            n -= 2;
            m -= 2;
            flag = false;
        }
    }
    if(n == 1 && m == 1)
    {
        if(!flag) b++;
        else w++;
    }
    else if(n == 1)
    {
        if(!flag) b += m;
        else w += m;
    }
    else if(m == 1)
    {
        if(!flag) b += n;
        else w += n;
    }
    cout << b << " " << w << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    #if ONLINE_JUDGE
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
    #endif
    int T = 1;
    cin >> T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}