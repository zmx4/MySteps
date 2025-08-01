#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 10;
const int mod = 998244353;
map<int, int> mp;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    int maxx = -2e18;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        maxx = max(maxx, a[i]);
    }
    int ans = 1;
    for(auto [x,y]:mp)if(x != maxx)ans=ans*(y+1)%mod;
    // ans /= 2;
    cout << ans << endl;
    return 0;
}