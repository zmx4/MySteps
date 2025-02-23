#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    ll sum = 0;
    int minNum = INT_MAX;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        minNum = min(minNum,a[i]);
    }
    for(int i=0;i<n;++i)
    {
        sum += a[i]-minNum;
    }
    cout<<sum<<endl;
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