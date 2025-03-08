#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{

    int n;cin>>n;
    vector<int>candy(n),orange(n);
    for(int i = 0;i < n;i++)cin>>candy[i];
    for(int i = 0;i < n;i++)cin>>orange[i];
    int mincan = *min_element(candy.begin(),candy.end());
    int minorg = *min_element(orange.begin(),orange.end());
    ll op = 0;
    for (int i = 0; i < n; i++)
    {
        int diffcan = candy[i] - mincan;
        int difforg = orange[i] - minorg;
        op += max(diffcan, difforg);
    }
    cout<<op<<endl;
    // int n;
    // cin >> n;
    // vector<int> a(n), b(n);
    // for (auto &it : a) cin >> it;
    // for (auto &it : b) cin >> it;
    // int mna = *min_element(a.begin(), a.end());
    // int mnb = *min_element(b.begin(), b.end());
    // long long ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     ans += max(a[i] - mna, b[i] - mnb);
    // }
    // cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}