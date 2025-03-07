#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;cin>>n;
    n *= 2;
    int odd=0,even=0;
    for(int i=0; i<n; i++)
    {
        int x;cin>>x;
        if(x%2)
            odd++;
        else
            even++;
    }
    if(odd == even)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
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