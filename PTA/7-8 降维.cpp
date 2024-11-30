#include<bits/stdc++.h>
using namespace std;
int a[2048][2048];
signed main()
{
    int n;cin>>n;
    //n++;
    for(int x = 1;x <= n;x++)
    {
        for(int y = 1;y <= n;y++)
        {
            cin>>a[x][y];
        }
    }
    
    string ans = "";
    for(int x = 1;x<=n;x+=2)
    {
        for(int y = 1;y <= n;y+=2)
        {
            ans+=to_string(a[x][y]);
            ans+=to_string(a[x][y+1]);
            ans+=to_string(a[x+1][y]);
            ans+=to_string(a[x+1][y+1]);
        }
    }
    cout<<ans;
}