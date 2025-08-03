#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);


    int n;cin>>n;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    vector<int> presum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        presum[i] = presum[i - 1] + a[i];

    if(presum[n]%3!= 0)
    cout << 0 << endl;
    else
    {
        int k = presum[n] / 3;
        int ans = 0, cnt = 0;
        for (int i = 1; i < n; i++)
        {
            if (presum[i] == 2 * k)
            {
                ans += cnt; // 累加满足条件的分割点数量
            }
            if (presum[i] == k)
            {
                cnt++; // 记录前缀和等于 k 的位置数量
            }
        }
        cout << ans << endl; // 输出结果
    }






    return 0;
}