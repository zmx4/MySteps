//24-11-27 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;
    int temp;
    while(t--)
    {
      cin>>temp;
      if(temp<=2)
      {
        cout<<"0"<<endl;
        continue;
      }
      if(temp%2==0)
      {
		    cout<<temp/2-1<<endl;
      }
      else if(temp%2==1)
      {
        cout<<temp/2<<endl;
      }
    }

    return 0;
}
