#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    vector<int>ans(n,0);
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = 0; j < 4; j++)
        {
            if(v[i][j] == '#')
            {
                ans[i] = j+1;
                break;
            }
        }
    }
    for(int i = n-1;i >= 0; i--)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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