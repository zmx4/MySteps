#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

void solve()
{
    int n,x;ll k;cin>>n>>x>>k;
    string op;cin>>op;
    int pos = x;
    bool flag = false;
    int cnt = 0;
    for(int i=0;i<op.size();i++)
    {
        --k;
        if(op[i] == 'L') pos--;
        else pos++;
        if(pos == 0 )
        {
            flag = true;
            break;
        }
    }
    ll ans = 0;
    if(flag)
    {
        ans = 1;
        for(int i = 0;i < n;i++)
        {
            if(op[i] == 'L') pos--;
            else pos++;
            if(pos==0)
            {
                ans+=k/(i+1);
                break;
            }
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