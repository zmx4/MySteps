//24-11-27 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    int a[200]={0},b[200]={0};

    int temp;
    int aq = 0,bq=0;
    for(int i=1;i<=n;i++)
    {
      cin>>temp;
      if(temp%2==0)
      {
      	b[i]++;
        bq++;
      }
      else
      {
        a[i]++;
        aq++;
      }
    }

    if(bq>aq)
    {
      for(int i=1;i<=n;i++)
      {
        if(a[i]!=0)cout<<i<<" ";
      }
    }
    else
    {
      for(int i=1;i<=n;i++)
      {
        if(b[i]!=0)cout<<i<<" ";
      }
    }
    return 0;
}
