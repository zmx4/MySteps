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
    int x0 = 0, x1 = 0, x2 = 0;
    for(int i = 0; i < n; i++)
    {
        ll x; cin >> x;
        if(x % 3 == 0) x0++;
        else if(x % 3 == 1) x1++;
        else x2++;
    }
    int ans = 0;
    ans+= x0 / 2;
    ans+=min(x1, x2);
    cout << ans << endl;
    return 0;
}