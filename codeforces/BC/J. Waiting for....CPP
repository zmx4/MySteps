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
    int quantity = 0,freeSet = 0;
    while(n--)
    {
      char ch;int p;cin>>ch>>p;
      if(ch=='P')quantity+=p;
      else if(ch=='B')
      {
      	freeSet+=p;
        if(freeSet>=quantity+1)
        {
          cout<<"YES"<<endl;
          freeSet=0;
          quantity=0;
        }
        else
        {
          cout<<"NO"<<endl;
          quantity-=freeSet;
          freeSet=0;
        }
      }
    }

    return 0;
}
