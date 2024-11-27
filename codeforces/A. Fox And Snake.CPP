//24-11-27 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n>>m;
    int a[n+1][m+1];
    /*
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        cin>>a[i][j];
      }
    }
  */

    char group[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
      {
        if(i%2==1)group[i][j]='#';
        else group[i][j]='.';
      }
    }

    int sign = 1;
    for(int i=1;i<=n;i++)
    {
      if(i%2==0)
      {
        if(sign==1)group[i][m]='#';
        else group[i][1]='#';
        sign*=-1;
      }
    }

    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)cout<<group[i][j];
      cout<<endl;
    }
    return 0;
}
