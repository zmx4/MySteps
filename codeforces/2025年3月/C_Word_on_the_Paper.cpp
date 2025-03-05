#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    char s[10][10];
    string str="";
    for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
            cin>>s[i][j];
            if(s[i][j] != '.')
                str += s[i][j];
        }
    cout<<str<<endl;
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