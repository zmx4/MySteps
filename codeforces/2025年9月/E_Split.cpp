#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define sc scanf
#define ff first
#define ss second
const int inf = 0x3f3f3f3f;
const ll llf = 0x3f3f3f3f3f3f3f3f;
typedef map<int, int> MII;
using ull = unsigned long long;
using uint = unsigned int;

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> p(n);
    for (auto &x : p)
        cin >> x;
    MII m;
    for (auto x : p)
        m[x]++;
    for (int i = 0; i <= n; i++)
    {
        if (m[i] % k)
        {
            cout << 0 << endl;
            return;
        }else
        {
            m[i] /= k;
        }
    }
    int res = 0;
    MII o;
    int l = 0, r = 0;
    for (; l <= r && r < n; r++)
    {
        o[p[r]]++;
        while (o[p[r]] > m[p[r]] / k)
        {
            o[p[l]]--;
            l++;
        }
        res += r - l + 1;
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}