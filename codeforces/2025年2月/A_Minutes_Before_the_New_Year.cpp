#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int hh,mm;
    cin>>hh>>mm;
    cout<<60*(23-hh)+60-mm<<endl;
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