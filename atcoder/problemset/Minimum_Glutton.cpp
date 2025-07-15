#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll X, Y;
    cin >> n >> X >> Y;
    vector<ll> A(n), B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    // 甜度降序、咸度降序
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    // 前缀和
    vector<ll> SA(n + 1, 0), SB(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        SA[i] = SA[i - 1] + A[i - 1];
        SB[i] = SB[i - 1] + B[i - 1];
    }
    // 二分最小 k 使得 SA[k]>X or SB[k]>Y
    int l = 1, r = n, ans = n;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (SA[m] > X || SB[m] > Y)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}