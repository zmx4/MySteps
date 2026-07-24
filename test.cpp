#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define int long long
// #define endl '\n'
const int mod = 998244353;
typedef struct
{
    int l, r, d;
} S;
bool cmp(int a, int b)
{
    return a > b;
}
// int a[110];
vector<int> a(110);
int n, h;

bool can(int k)
{
    int sum = 0;
    for (int i = 2; i <= n; i++)
    {
        sum += min(k, a[i] - a[i - 1]);
    }
    sum += k;
    return sum >= h;
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    int t;
    cin >> t;
    
    while (t--)
    {
        cin >> n >> h;
        for (int i = 1; i <= 110; i++)
            a[i] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
            // ranges::sort(a.begin() + 1, a.begin() + n + 1, cmp);
        int sum = 0;
        int l = 1, r = h;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (can(mid))
                r = mid - 1;
            else
                l = mid + 1;
        }
        cout << l << endl;
    }
    return 0;
}