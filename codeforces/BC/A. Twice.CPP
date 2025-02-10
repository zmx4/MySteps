//24-11-28 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    while(n--)
    {
      int t;cin>>t;
      int a[510]={0};int temp;
      for(int i=0;i<t;i++)
      {
      	cin>>temp;
        a[temp]++;
      }

      int cnt = 0;
      if(t==1)
      {
        cout<<0<<endl;
        continue;
      }
      else if(t>=2)
      {
        for(int i=0;i<510;i++)
        {
          if(a[i]>1)cnt += a[i] / 2;
        }
        //cout<<cnt<<endl;
      }
      cout<<cnt<<endl;
    }

    return 0;
}
