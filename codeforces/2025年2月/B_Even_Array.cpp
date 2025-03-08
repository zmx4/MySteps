#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int odd=0,even=0;
    for(int i=0;i<n;i++)
    {
        if(i%2!=a[i]%2)
        {
            if(i%2==0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
    }
    if(odd!=even)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<odd<<endl;
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