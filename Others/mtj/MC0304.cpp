#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

int n, F;
vector<ll> a;

bool check(int M)
{
    ll minS = 0, S = 0;
    vector<ll> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ll Bi = a[i] - M;
        S += Bi;
        pre[i] = S;
    }
    minS = 0;
    for (int i = F; i <= n; i++)
    {
        minS = min(minS, pre[i - F]);
        if (pre[i] - minS >= 0)
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> F;
    a.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        a[i] = x * 1000;
    }
    int l = 0, r = 2000 * 1000;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << endl;
    return 0;
}