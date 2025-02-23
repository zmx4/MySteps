#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;cin>>n;
    vector<int> a(n-2);
    for(int i=0;i<n-2;++i)
    {
        cin>>a[i];
    }
    for(int i = 0;i < n - 4;i++)
    {
        if(a[i]==1&&a[i+1]==0&&a[i+2]==1)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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