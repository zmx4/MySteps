#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    for(int i = 0; i < n; i++)
    {
        if(s1[i]=='G')s1[i]='B';
        if(s2[i]=='G')s2[i]='B';
    }
    if(s1==s2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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