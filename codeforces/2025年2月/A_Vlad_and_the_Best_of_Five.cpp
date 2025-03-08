#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int a = 0,b = 0;
    for(int i=0;i<5;++i)
    {
        if(s[i]=='A')
        {
            a++;
        }
        else
        {
            b++;
        }
    }
    if(a>b)
    {
        cout<<"A"<<endl;
    }
    else
    {
        cout<<"B"<<endl;
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