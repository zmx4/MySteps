//24-11-24 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,q;cin>>n>>q;
    string a,b;cin>>a>>b;
    while(q--)
    {
      int x;cin>>x;
      x--;
      swap(a[x],b[x]);
      cout<<a<<" "<<b<<endl;
    }

    return 0;
}
