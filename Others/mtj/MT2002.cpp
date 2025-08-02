#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
bool vis[N]; // 声明 vis 数组，大小为 N
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);


    int n;cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    // vector<int>buckets(n, 0);
    // sort(a.begin(), a.end());
    int k = n;
    while(1)
    {
        int i;
        memset(vis, 0, sizeof(vis)); // 清空 vis 数组
        // vector<int>vis(n+1, 0);
        for(i = 0;i < n;i++)
        {
            if (vis[a[i] % k])
            {
                k++;
                break;
            }
            vis[a[i]%k] = 1;
        }
        if(i==n)
        {
            cout << k << endl;
            break;
        }
    }

    return 0;
}