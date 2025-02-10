//24-11-24 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    while(n--)
    {
      int a,b;cin>>a>>b;
      int c=a%b;
    	if(c==0)cout<<"0"<<endl;
    	else cout<<b-c<<endl;
    }

    return 0;
}
