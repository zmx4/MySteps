#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const int N = 1e6+10;
bool in[N + 10];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n, m;

    cin >> n >> m;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    map<ll, int> mp;
    vector<ll> b(n+1);
    for (int i = n ; i > 0;i--)
    {
        if(mp[a[i]] == 0)
        {
            // mp[a[i]] = i;
            b[i] = N;
        }
        else
        {
            b[i] =mp[a[i]];
            
        }
        mp[a[i]] = i;
    }
    priority_queue<ll> pq;
    int ans = 0, cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!in[i])
        {
            ans++;
            if(cnt < m)
            {
                cnt++;
                in[b[i]] = 1;
                pq.push(b[i]);
            }
            else
            {
                in[pq.top()] = 0;
                pq.pop();
                in[b[i]] = 1;
                pq.push(b[i]);
            }
        }
        else
        {
            in[b[i]] = 1;
            pq.push(b[i]);
        }
    }
    cout << ans << endl;
    return 0;
}