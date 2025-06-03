#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
string s;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> s;
    int sum = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        int v = s[i] - '0';
        int u = ((i < n - 1) ? (s[i + 1] - '0') : 0);
        int b = (10 + v - u) % 10;
        sum += b;
    }

    int ans = sum + n;
    cout << ans << "\n";

    return 0;
}