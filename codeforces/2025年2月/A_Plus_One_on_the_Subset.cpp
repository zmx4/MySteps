#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int avg=sum/n;
    sort(a.begin(),a.end());
    int ans1=0,ans2=0;
    
    cout<<a.back()-*(a.begin())<<endl;
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