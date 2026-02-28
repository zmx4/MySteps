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

    int n;
    cin >> n;

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        // int y = x / 3;
        if(x != 1) ++ ans;
    }

    cout << ans << endl;






    return 0;
}