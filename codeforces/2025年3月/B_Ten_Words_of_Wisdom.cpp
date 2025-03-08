#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin>>n;
    pair<int,int>part,best;
    best = make_pair(9,0);
    int pos = 0;
    for(int i = 1;i <= n;i++)
    {
        cin>>part.first>>part.second;
        if(part.second>best.second&&part.first<=10)best = part,pos = i;
    }
    cout<<pos<<endl;
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