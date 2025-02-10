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
    int cnt = 0;
    while(n--)
    {
      string s;cin>>s;
      if(s=="Tetrahedron")cnt+=4;
      else if(s=="Cube")cnt+=6;
      else if(s=="Octahedron")cnt+=8;
      else if(s=="Dodecahedron")cnt+=12;
      else if(s=="Icosahedron")cnt+=20;
    }
	cout<<cnt;
    return 0;
}
