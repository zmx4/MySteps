#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int n, t;
    cin >> n >> t;
    vector<int> a(n),qz(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        qz[i+1] = qz[i] + a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(qz.begin(), qz.end(), qz[i] + t) - qz.begin()-1;
        ans = max(ans, j - i);
    }
    cout << ans << endl;
    return 0;
}