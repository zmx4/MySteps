#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n;
    cin>>n;
    vector<ll> a(n+1);

    for(int i = 1;i <= n;i++)cin>>a[i];
    vector<ll> b=a;
    sort(b.begin(),b.end());
    for(int i = 1;i <= n;i++)b[i]+=b[i-1];
    int m;
    cin>>m;
    while(m--)
    {
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1)
        {
            cout<<accumulate(a.begin()+l,a.begin()+r+1,0ll)<<endl;
        }
        else
        {
            cout<<b[r]-b[l-1]<<endl;
        }
    }
    return 0;
}