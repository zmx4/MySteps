#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    *min_element(a.begin(),a.end())+=1;
    int sum = a[0];
    for(int i=1;i<n;++i)
    {
        sum*=a[i];
    }
    cout<<sum<<endl;
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