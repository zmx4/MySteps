#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    bool flag=false;
    for(int i = 0;i < n-1;i++)
    {
        if(s[i]==s[i+1])flag=true;
    }
    if(flag)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<n<<endl;
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