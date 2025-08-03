#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
bool vis[N];
int ne[N];
int last[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n, m, p;
    while(cin >> n >> m >> p)
    {
        memset(vis, false, sizeof(vis));
        memset(ne, 0, sizeof(ne));
        vector<int> a(p + 1);
        for (int i = 1; i <= p; i++)
            cin >> a[i];
        fill(last + 1, last + m + 1, inf);
        for (int i = p; i >= 1; i--)
        {
            ne[i] = last[a[i]];
            last[a[i]] = i;
        }
        int ans = 0;
        priority_queue<pair<int, int>> q;
        for (int i = 1; i <= p; i++)
        {
            if(ans < n&&!vis[a[i]])
            {
                ans++;
                vis[a[i]] = true;
            }else if (ans >= n && !vis[a[i]])
            {
                ans++;
                vis[q.top().second] = false;
                vis[a[i]] = true;
                q.pop();
            }
            q.push({ne[i], a[i]});
        }
        cout << ans << endl;
    }

    return 0;
}