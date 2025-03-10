#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int lcm(int a,int b)
{
    return a*b/__gcd(a,b);
}

void solve()
{
    int x,y;
    cin>>x>>y;
    if(x*2>y)
    {
        cout<<-1<<" "<<-1<<endl;
    }
    else
    {
        cout<<x<<" "<<x*2<<endl;
    }
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