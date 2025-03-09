#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N = 1E9+7;


void solve()
{
    int n;
    cin>>n;
    int ans = (n/15)*3;
    n %=15;
    for(int i = 0;i <= n;i++)
    {
        if(i%3 == i%5)
        {
            ans++;
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