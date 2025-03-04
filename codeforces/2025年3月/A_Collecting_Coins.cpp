#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    int maxn = max(a,max(b,c));
    int sum = 3*maxn-a-b-c;
    if(n<sum)
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        n-=sum;
        if(n%3==0)
        {
            cout<<"YES"<<endl;
            return;
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
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