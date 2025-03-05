#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    pair<int,int> pos = {0,0},target = {1,1};
    int n;cin>>n;
    string s;
    cin>>s;
    bool flag = false;
    for(int i=0; i<n; i++)
    {
        if(s[i] == 'L')
            pos.first--;
        else if(s[i] == 'R')
            pos.first++;
        else if(s[i] == 'U')
            pos.second++;
        else
            pos.second--;
        if( target == pos)
        {
            flag = true;
            break;
        }
    }
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
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