//24-11-26 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    int home[n+1],guest[n+1];
    for(int i=1;i<=n;i++)
    {
      cin>>home[i]>>guest[i];
    }

    int cnt = 0;
	for(int i=1;i<=n;i++)
    {
          for(int j=1;j<=n;j++)
          {
            if(guest[i]==home[j])cnt++;
          }
    }

    cout<<cnt;
    return 0;
}
