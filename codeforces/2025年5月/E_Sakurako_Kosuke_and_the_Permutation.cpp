#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
vector<int> vis;
vector<int> a;
void solve()
{
    int n;
    cin>>n;
    vis.assign(n + 1, 0);
    a.assign(n + 1, 0);
    for(int i = 1;i <= n;i++)cin>>a[i];
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(vis[i])continue;
        int cnt = 0;
        int cur = i;
        while(!vis[cur])
        {
            vis[cur] = 1;
            cur = a[cur];
            cnt++;
        }
        ans += (cnt-1)/2;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    // char readBuffer[1 << 20];
    // cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T = 1;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}