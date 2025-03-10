#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    vector<int> a(3);
    for (int i = 0; i < 3; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // int ans = INT_MAX;
    // for(int i = 1;i < 11;i++)
    // {
    //     ans = min(ans, abs(a[0] - i) + abs(a[1] - i) + abs(a[2] - i));
    // }
    // cout<<ans<<endl;
    cout << a[2] - a[0] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}