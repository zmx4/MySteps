#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define gcd __gcd
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
    if(x==1)
    {
        for(int i=2;i<=y;i++)
        {
            if(y%i==0)
            {
                cout<<i<<endl;
                return;
            }
        }
    }
    else if(y==1)
    {
        for(int i=2;i<=x;i++)
        {
            if(x%i==0)
            {
                cout<<i<<endl;
                return;
            }
        }
    }
    int a = gcd(x,y);
    if(a>1)
    {
        cout<<a<<endl;
        return;
    }
    cout<<x*y<<endl;
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