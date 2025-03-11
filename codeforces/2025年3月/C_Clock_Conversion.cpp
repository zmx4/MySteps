#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int hh,mm;
    cin>>hh;
    cin.ignore();
    cin>>mm;
    if(hh < 12)
    {
        if(hh == 0)
        {
            hh = 12;
        }
        cout<<setfill('0')<<setw(2)<<hh<<":"<<setfill('0')<<setw(2)<<mm<<" AM"<<endl;
    }
    else
    {
        if(hh > 12)
        {
            hh -= 12;
        }
        cout<<setfill('0')<<setw(2)<<hh<<":"<<setfill('0')<<setw(2)<<mm<<" PM"<<endl;
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