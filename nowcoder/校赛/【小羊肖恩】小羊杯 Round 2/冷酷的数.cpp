#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int x,y;
    cin>>x>>y;
    if(x==1&&y==1)
    {
        cout<<-1<<endl;
        return;
    }
    int maxn=max(x,y);
    for(int i=2;i<=maxn;i++)
    {
        if(gcd(i,x)==1&&gcd(i,y)==1)
        {
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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