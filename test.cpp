#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int valand = a[1], valor = a[1];
    for (int i = 2; i <= n; i++)
    {
        valand &= a[i];
        valor |= a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    cout << valor  << endl;
    return 0;
}