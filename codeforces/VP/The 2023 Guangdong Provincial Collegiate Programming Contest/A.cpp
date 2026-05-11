#include<bits/stdc++.h>
using namespace std;
#define int long long




void solve()
{
    int st;
    cin >> st;
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x:a)
        cin >> x;
    int end;
    cin >> end;
    int ans = end - st + 1;
    for(auto x:a)
    {
        if(x > end)
            break;
        ans--;
    }
    cout << ans << endl;
}



signed main()
{
    int T = 1;
    cin >> T;
    while(T--)
    {
        solve();
    }
}