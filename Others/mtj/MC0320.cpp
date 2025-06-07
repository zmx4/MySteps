#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || s[i] != s[i - 1])
        {
            ans += (i + 1);
        }
        else
        {
            ans += 1;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T = 1;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}