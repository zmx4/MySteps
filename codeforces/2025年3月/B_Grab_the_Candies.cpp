#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a,b;
    for(int i = 0;i<n;i++)
    {
        int x;cin>>x;
        if(x%2 == 0)
        {
            a.push_back(x);
        }
        else
        {
            b.push_back(x);
        }
    }
    if(accumulate(a.begin(),a.end(),0) <= accumulate(b.begin(),b.end(),0))
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
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