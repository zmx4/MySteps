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
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++)cin>>a[i];
    int ans = 0;
    for (int i = 1; i <= n;i++)
    {
        for(int j = i;j <= n;j++)
        {
            if(a[i] < a[j])
            {
                ans++;
                swap(a[i],a[j]);
            }
        }
    }
    cout<<ans<<endl;
        return 0;
}