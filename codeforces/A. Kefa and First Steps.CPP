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
    int a[n];
    int cnt=0,temp = 1;
	cin>>a[0];
    for(int i=1;i<n;i++)
    {
      cin>>a[i];
	  if(a[i]>=a[i-1])temp++;
      else
      {
      	cnt = max(temp,cnt);
      	temp = 1;
      }
    }
	cnt = max(temp,cnt);
	cout<<cnt;
    return 0;
}
