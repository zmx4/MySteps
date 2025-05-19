#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 5000;
int a[N][N];
void solve()
{
    int n;
    cin>>n;
    int len = 1010;
    int idx = 0,t = 0;
    int l, r, u, d;
    l = r = u = d = 0;
    while(idx < n*n - 1)
    {
        if(t % 4==0)
        {
            for(int i = u; i <= d; i++)
            {
                a[len + i][len + r + 1] = ++idx;
            }
            r++;
        }
        else if(t  % 4 == 1)
        {
            for(int i = r; i >= l; i--)
            {
                a[len + d + 1][len + i] = ++idx;
            }
            d++;
        }
        else if(t % 4 == 2)
        {
            for(int i = d; i >= u; i--)
            {
                a[len + i][len + l - 1] = ++idx;
            }
            l--;
        }
        else
        {
            for(int i = l; i <= r; i++)
            {
                a[len + u - 1][len + i] = ++idx;
            }
            u--;
        }
        t++;
    }
    for(int i = u;i <= d; i++)
    {
        for(int j = l; j <= r; j++)
        {
            cout<<a[len + i][len + j]<<" ";
        }
        cout<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}