#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n),b(m);
    for(int i = 0;i < n;i++)cin>>a[i];
    for(int i = 0;i < m;i++)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        if(a[i]<k)
        {
            auto it = upper_bound(b.begin(),b.end(),k-a[i]);
            ans+=(it-b.begin());
        }
    }
    cout<<ans<<endl;
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