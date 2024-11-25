//24-11-24 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e5+10;
int a[N],b[110][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=100;i++)
    {
      for(int j=1;j<=n;j++)b[i][j]=abs(a[j]-i);
    }
    for(int i=1;i<=100;i++)
    {
      for(int j=1;j<=n;j++)
      {
        b[i][j]+=b[i][j-1];
      }
    }
    while(m--)
    {
      int res = INT_MAX;
      int l,r;cin>>l>>r;
      for(int i=1;i<=100;i++)
      {
        res=min(res,b[i][r]-b[i][l-1]);
      }
      cout<<res<<endl;
    }

    return 0;
}
