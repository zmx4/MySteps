#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
const int mod = 1e9+7;

ll C(int n, int m) {
    if (m > n || m < 0) return 0;
    if (m == 0 || m == n) return 1;
    ll res = 1;
    for (int i = 1; i <= m; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);


    string s;
    cin >> s;
    ll ans = 0;
    int cnt = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '1') {
            cnt++;
        }
        if(s[i] == '0' && cnt > 0) {
            (ans += C(cnt+1, 2))%= mod;
            cnt = 0;
        }
    }
    if(cnt > 0) {
        (ans += C(cnt+1, 2))%= mod;
    }
    cout << ans << endl;






    return 0;
}