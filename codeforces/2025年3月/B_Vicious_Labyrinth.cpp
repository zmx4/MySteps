#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

inline void solve()
{
    
    ll n, k;
    cin >> n >> k;

    if(k%2ll==0ll)
    {
        for(ll i = 1;i < n-1;i++)cout<<n-1<<" ";
        cout<<n<<" "<<n-1<<endl;
    }
    else
    {
        for(ll i = 1;i <= n-1;i++)cout<<n<<" ";
        cout<<n-1<<endl;
    }
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