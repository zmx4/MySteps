#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l=0,r=n-1;
    int cnt = 0;
    while(s[l]!=s[r] && l<r)
    {
        l++;
        r--;
        cnt++;
    }
    cout<<s.size()-cnt*2<<endl;
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