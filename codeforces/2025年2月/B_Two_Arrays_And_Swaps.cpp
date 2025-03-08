#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;
    int am=n,bm=n;
    priority_queue<int> b;
    priority_queue<int,vector<int>,greater<int>> a;
    for(int i=0;i<am;i++)
    {
        int x;cin>>x;
        a.push(x);
    }
    for(int i=0;i<bm;i++)
    {
        int x;cin>>x;
        b.push(x);
    }
    while(!b.empty()&&k!=0)
    {
        if(a.top()<b.top())
        {
            a.pop();
            a.push(b.top());
            b.pop();
            k--;
        }
        else
        {
            b.pop();
        }
    }
    ll ans=0;
    while(!a.empty())
    {
        ans+=a.top();
        a.pop();
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