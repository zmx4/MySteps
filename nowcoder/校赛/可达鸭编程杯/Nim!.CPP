//24-11-23 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;
    while(t--)
    {
      int n;cin>>n;
      int a[n];
      for(int i=0;i<n;i++)cin>>a[i];
      sort(a,a+n);
      int cnt = 0;
      for(int i=0;i<n;i++)
      {
        if(a[i]==1)cnt++;
      }
      if(cnt==n)
      {
        if(cnt%2==1)
        {
          cout<<"Cxlian"<<endl;
        }
        else
        {
          cout<<"Student"<<endl;
        }
      }
      else
      {
        if(cnt%2==1)
        {
          cout<<"Student"<<endl;
        }
        else
        {
          cout<<"Cxlian"<<endl;
        }
      }
    }

    return 0;
}
