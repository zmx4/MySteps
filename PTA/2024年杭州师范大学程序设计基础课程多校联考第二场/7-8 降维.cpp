#include<bits/stdc++.h>
using namespace std;
int a[2048][2048];
string ans = "";
int n;
void solve(const int &aa,const int &bb,const int &xx,const int &yy)
{
    cout<<aa<<bb<<xx<<yy<<endl;
    if(xx-yy==1)
    {
        ans+=to_string(a[xx][yy]);
        ans+=to_string(a[xx][yy+1]);
        ans+=to_string(a[xx+1][yy]);
        ans+=to_string(a[xx+1][yy+1]);
    }
    if(xx - aa == 1 && yy - bb == 1)
    {
        solve(1,1,xx/2,yy/2);
        solve((xx/2)+1,(yy/2)+1,xx,yy);
        solve(1+(xx/2),1,1,yy/2);
        solve(1,1+(yy/2),xx/2,1);
    }
}
signed main()
{
    cin>>n;
    //n++;
    for(int x = 1;x <= n;x++)
    {
        for(int y = 1;y <= n;y++)
        {
            cin>>a[x][y];
        }
    }
    
    string ans = "";
    solve(1,1,n,n);
    cout<<ans;
}