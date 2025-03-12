#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < n;i++)cin>>v[i];
    sort(v.begin(),v.end(),greater<int>());
    while(v.size()>1)
    {
        int a = v.back();v.pop_back();
        int b = v.back();v.pop_back();
        v.push_back(a+b-1);
    }
    cout<<v[0]<<endl;

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