#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 10), b(n + 10);
    int suma = 0, sumb = 0;
    vector<int> diff;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        suma += a[i];
        sumb += b[i];
        if(b[i] > a[i])
            diff.push_back(b[i] - a[i]);
    }
    if(n == 1)
    {
        cout << sumb << endl;
        return;
    }
    std::ranges::sort(diff, greater<int>());

    int maxd = min(n - 2, m - n);
    int ans1 = suma;
    for (int i = 0;i < min(maxd, (int)diff.size()); i++)
    {
        ans1 += diff[i];
    }
    int ans2 = 0;
    if(2 * n - 1 <= m){
        ans2 = sumb;
    }
    cout << max(ans1, ans2) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}