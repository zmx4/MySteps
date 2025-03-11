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
    map<string,int> mp;
    for(int i = 0;i < n-1;i++)
    {
        string temp = s.substr(i,2);
        mp[temp]++;
    }
    int ans = 0;
    string res;
    for(auto x:mp)
    {
        if(x.second>ans)
        {
            ans = x.second;
            res = x.first;
        }
    }
    cout<<res<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T=1;
    while(T--)
    {
        solve();
    }
    
    return 0;
}