#include<bits/stdc++.h>
using namespace std;

int a[110][110];

signed main()
{
    int n,m,k;cin>>n>>m>>k;
    int x,y;cin>>x>>y;
    while(k--)
    {
        int xx,yy,s;
        cin>>xx>>yy>>s;
        a[xx][yy]+=s+1;
    }
    int possiblePosition = 0;
    if(x-2>0)
    {
        if(a[x-1][y]==0)
        {
            if(a[x-2][y-1]<2&&y-1>0)
            {
                possiblePosition++;
            }
            if(a[x-2][y+1]<2&&y+1<=m)
            {
                possiblePosition++;
            }
            //cout<<"d"<<endl;
        }
    }
    if(x+2<=n)
    {
        if(a[x+1][y]==0)
        {
            if(a[x+2][y-1]<2&&y-1>0)
            {
                possiblePosition++;
            }
            if(a[x+2][y+1]<2&&y+1<=m)
            {
                possiblePosition++;
            }
            //cout<<"c"<<endl;
        }
    }
    if(y-2>0)
    {
        if(a[x][y-1]==0)
        {
            if(a[x-1][y-2]<2&&x-1>0)
            {
                possiblePosition++;
            }
            if(a[x+1][y-2]<2&&x+1<=n)
            {
                possiblePosition++;
            }
        }
        //cout<<"b"<<endl;
    }
    if(y+2<=m)
    {
        if(a[x][y+1]==0)
        {
            if(a[x-1][y+2]<2&&x-1>0)
            {
                possiblePosition++;
            }
            if(a[x+1][y+2]<2&&x+1<=n)
            {
                possiblePosition++;
            }
            //cout<<"a"<<endl;
        }
    }
    cout<<possiblePosition;
}