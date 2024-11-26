//24-11-26 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k,l,m,n,d;cin>>k>>l>>m>>n>>d;
    bool safe[100005]={false};
    int temp;
    for(int i=0;i<=d;i+=k)
    {
      //cin>>temp;
      safe[i]=true;
    }
    for(int i=0;i<=d;i+=l)
    {
    	//cin>>temp;
    	safe[i]=true;
    }
    for(int i=0;i<=d;i+=m)
    {
      //cin>>temp;
      safe[i]=true;
    }
    for(int i=0;i<=d;i+=n)
    {
      safe[i]=true;
    }
    int cnt=0;
    for(int i=1;i<=d;i++)
    {
      if(!safe[i])
      {
        cnt++;
        //cout<<i<<" ";
      }
    }
    //if (d-cnt!=0)cout<<d-cnt;
    //else cout<<"0";
    //cout<<"0qwdewafevsfv";
    cout<<d-cnt;
    return 0;
}
