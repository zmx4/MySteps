//24-11-24 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long
int gcd3(int a, int b, int c) {
	return gcd(gcd(a, b), c);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,h;cin>>n>>h;
    while(n--)
    {
      int x,y,z;cin>>x>>y>>z;
      int vx=x,vy=y,vz=2*h-z;
      int a = gcd3(vx,vy,vz);
      cout<<vx/a<<" "<<vy/a<<" "<<vz/a<<" "<<endl;
    }

    return 0;
}
