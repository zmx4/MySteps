#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

bool judge(const string &s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return s < t;
}

void solve()
{
    int n,k;cin>>n>>k;
    string s;cin>>s;
    //cout<<s<<endl;
    int len = s.size();
    if(len == 1)cout<<"NO"<<endl;
    else if(judge(s))cout<<"YES"<<endl;
    else
    {
        char minchar ,maxchar;
        minchar = s[0];
        maxchar = s[0];
        for(int i = 0;i < len;i++)
        {
            if(s[i] < minchar)minchar = s[i];
            if(s[i] > maxchar)maxchar = s[i];
        }
        if(minchar == maxchar)cout<<"NO"<<endl;
        else
        {
            if(k < 1)cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
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