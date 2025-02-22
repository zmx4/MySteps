#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin>>n;
    ll cnt1 = 0,cnt2 = 0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }
    ll a=0,b=0;
    while(cnt2>0)
    {
        if(a>b)
        {
            b+=2;
            cnt2--;
        }
        else
        {
            a+=2;
            cnt2--;
        }
    }
    while(cnt1>0)
    {
        if(a>b)
        {
            b++;
            cnt1--;
        }
        else
        {
            a++;
            cnt1--;
        }
    }
    if(a==b)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
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