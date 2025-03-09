#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n,k,p;cin>>n>>k>>p;
    if(abs(k) > n*p)
    {
        cout<<-1<<endl;
        return;
    }
    k = abs(k);
    int cnt = 0,sum = 0;
    
    while(sum < k)
    {
        sum+=p;
        cnt++;
    }
    cout<<cnt<<endl;
    return;
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