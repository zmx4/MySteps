#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n, m;
    cin>> n >> m;
    map<int, int> mp;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>> x;
        mp[x]++;
    }
    int ans = 0;
    for(auto [k, v]:mp)
    {
        ans = max(ans, k * min(m, v));
    }
    cout<< ans << endl;

    return 0;
}